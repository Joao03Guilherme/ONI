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
	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; st.insert(x);
	}
	cout << st.size() << "\n";
}

void p2() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> a(n); for (int& x : a) cin >> x;

	vector<int> l;
	int i = 0, j = 0;
	while (i < n) {
		int mx_len = 0;
		while (j < n && a[i] == a[j]) {
			mx_len++; j++;
		}
		l.pb(mx_len);
		i = j;
	}

	sort(l.begin(), l.end());
	int ans = 0;
	for (int i = 0; i < (int)l.size()-x; i++) {
		ans += l[i];
	}
	cout << ans << "\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else p2();
    return 0;
}