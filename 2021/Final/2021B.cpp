# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void p1() {
	int n, k; cin >> n >> k;
	vector<int> v(n); for (int& x : v) cin >> x;

	set<int, greater<int>> st;
	vector<int> ans;
	// First window
	for (int i = 1; i < min(n, k+1); i++) {
		st.insert(v[i]);
	}

	auto itr = st.upper_bound(v[0]);
	if (itr == st.end()) ans.pb(-1);
	else ans.pb(*itr);

	for (int i = 1; i < n; i++) {
		st.insert(v[i-1]);
		st.erase(v[i]);
		if (i + k < n) st.insert(v[i+k]);
		if (i - k - 1 >= 0) st.erase(v[i - k - 1]);

		auto itr = st.upper_bound(v[i]);
		if (itr == st.end()) ans.pb(-1);
		else ans.pb(*itr);
	}

	for (int i = 0; i < n-1; i++) cout << ans[i] << " ";
	cout << ans[n-1] << "\n";
}

bool partition(vector<int>& v, int k, int val) {
	int cnt = 0;
	for (int x : v) { // Isto é desnecessário, dá para pré computar
		if (x >= val) cnt++;
	}
	return cnt > k / 2; 
}

void p2() {
	int n, k; cin >> n >> k;
	vector<int> v(n); for (int& x : v) cin >> x;

	int l = 0, r = 1e9 + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		bool test = partition(v, k, mid);
		if (test) l = mid;
		else r = mid;
	} 
	cout << l << "\n";
}


int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else p2();
    return 0;
}

