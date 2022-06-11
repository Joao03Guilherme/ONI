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

	map<int, int> mp;
	for (int x : v) mp[x]++;

	int mx = -1, ans = 0;
	for (pii p : mp) {
		if (p.second > mx) {
			mx = p.second;
			ans = p.first;
		} else if (p.second == mx) {
			ans = 0;
		}
	}

	cout << ans << "\n";
}

void p2() {
	int n, k; cin >> n >> k;
	vector<int> v(n); for (int& x : v) cin >> x;

	map<int, int> mp;
	for (int i = 1; i <= k; i++) mp[i] = 0;
	for (int x : v) mp[x]++;
	for (pii p : mp) {
		if (p.first == k) cout << p.second << "\n";
		else cout << p.second << " ";
	}
}

void p3() {
	int n, k; cin >> n >> k;
	vector<vector<int>> preferences(k+1, vector<int>(k+1, 0));

	for (int i = 0; i < n; i++) {
		vector<int> a(k);
		for (int& x : a) cin >> x;

		for (int i = 0; i < k; i++) {
			for (int j = i+1; j < k; j++) {
				preferences[ a[i] ][ a[j] ]++; // A lista a[i] é preferida à lista a[j]
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		int cnt = 0;
		for (int j = 1; j <= k; j++) {
			if (i == j) continue;
			if (preferences[i][j] > preferences[j][i]) cnt++;
		}
		if (cnt == k-1) {
			cout << i << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else if (p == 2) p2();
    else p3();
    return 0;
}