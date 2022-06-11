# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 900;

int l, c, r;
int dp[MX][MX];
int grid[MX][MX];
vector<pair<int, int>> rectangles;

bool test(int mid, pii rectangle) {
	memset(dp, 0, sizeof(dp));
	int grid2[MX][MX];
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			grid2[i][j] = (grid[i][j] < mid) ? 1 : 0;
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0) dp[0][j] = grid2[0][j];
			else {
				if (grid2[i][j] == 0) dp[i][j] = 0;
				else dp[i][j] = dp[i-1][j] + 1;
			}
		}
	}

	// Find largest rectangle in each histogram
	for (int i = 0; i < l; i++) {
		stack<int> s;
		for (int j = 0; j < c; j++) {
			int start = i;
			while(!s.empty() && dp[i][s.top()] > dp[i][j]) {
				int x = s.top(); s.pop();
				int altura = dp[i][x];
				int comprimento = j - x;
				if (altura >= rectangle.first && comprimento >= rectangle.second) return true;
				start = x;
				dp[i][start] = dp[i][j];
			}
			s.push(start);
		}

		while (!s.empty()) {
			int x = s.top(); s.pop();
			int altura = dp[i][x];
			int comprimento = c - x;
			if (altura >= rectangle.first && comprimento >= rectangle.second) return true;
		}
	}

	return false;
}

int main() 
{
	IOS;
	cin >> l >> c;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	cin >> r;
	for (int i = 0; i < r; i++) {
		int a, b; cin >> a >> b;
		rectangles.pb({a, b});
	}

	for (pii rectangle : rectangles) {
		int l = -1, r = 1'000'001;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (test(mid, rectangle)) {
				r = mid;
			} else l = mid;
		}
		cout << r << "\n";
	}
	return 0;
}