# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

const int MX = 1'000'000'001;


void p1() {
	int n; cin >> n;
	unordered_set<string> st;
	for (int i=0;i<n;i++) {
		string arame = "";
		int k; cin >> k;
		arame += to_string(k) + '-';
		while(k--) {
			int x; cin >> x;
			arame += to_string(x) + '-';
		}
		st.insert(arame);
	}
	cout << st.size() << "\n";
	return;
}

void p2() {
	int n; cin >> n;
	vector<vector<ll>> abaco;
	for (int i = 0; i < n; i++) {
		vector<ll> arame;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			ll x; cin >> x; arame.pb(x);
		}
		abaco.pb(arame);
	}

	int q; cin >> q;
	ll pos_1 = 1;
	ll min_pos = 1;
	ll pos = 1;
	while (q--) {
		char o; ll d; cin >> o >> d;
		if (o == 'E') {
			pos += - d;
			min_pos = min(min_pos, pos);
			pos_1 = max(1ll, pos_1 - d);
		} else {
			pos += d;
			pos_1 += d;
		}
	}

	for (vector<ll> arame : abaco) {
		for (int i = 0; i < (int)arame.size()-1; i++) {
			if (-min_pos + 1 >= arame[i] - i) {
				cout << pos_1 + i << " ";
			} else {
				cout << arame[i] + pos - 1 << " ";
			}
		}
		if (-min_pos + 1 >= arame[(int)arame.size() - 1] - (int)arame.size()-1) {
			cout << pos_1 + (int)arame.size()-1;
		} else {
			cout << arame[(int)arame.size() - 1] + pos - 1;
		}
		cout << "\n";
	}
	return;
}

int main() 
{
	IOS;
	int p; cin >> p;
	if (p == 1) p1();
	else p2();
	return 0;
}