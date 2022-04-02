# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

const int MX = 65536;
const int LOG = 16;
int m_min[MX][LOG];
int m_max[MX][LOG];

int query_min(int l, int r) {
	int len = r - l + 1;
	int k = floor(log2(len));
	return min(m_min[l][k], m_min[r - (1<<k) + 1][k]);
}

int query_max(int l, int r) {
	int len = r - l + 1;
	int k = floor(log2(len));
	return max(m_max[l][k], m_max[r - (1<<k) + 1][k]);
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	int c; cin >> c;
	while (c--) {
		int n, d; cin >> n >> d;
		vector<int> a(n); for(int& x : a) cin >> x;

		// Implementar sparse table 
		for (int i = 0; i < n; i++) {
			m_min[i][0] = m_max[i][0] = a[i];
		}

		for (int k = 1; k < LOG; k++) {
			for (int i = 0; i + (1<<k) - 1 < n; i++) {
				m_min[i][k] = min(m_min[i][k-1], m_min[i + (1<<(k-1))][k-1]);
				m_max[i][k] = max(m_max[i][k-1], m_max[i + (1<<(k-1))][k-1]);
			}
		} // 0(N*LOG(N))

		ll ans = 0;
		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) mp[a[i]].pb(i);

		for (pair<int, vector<int>> p : mp) {
			int a = p.first; vector<int> v = p.second;
			int parity = 1;

			int l = 0, r = v.size()-1;
			while (l < r) {
				int mn = query_min(v[l], v[r]), mx = query_max(v[l], v[r]);
				if (max(abs(a-mn), abs(a-mx)) <= d) {
					ans += ((r-l+1) * (r-l)) / 2; break;
				}
				if (parity) {
					l++;
				}
				else {
					r--;
				}
				parity = 1 - parity;
			}
		} // O(N) -> Visitamos cada elemento 1 vez
		// Complexidade final: O(N*Log(N))
		cout << ans << "\n";
	}
	return 0;
}