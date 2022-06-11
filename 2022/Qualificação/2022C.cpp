# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 1'001;

void p1() {
	int d; cin >> d;
	vector<vector<int>> grid(d, vector<int>(d));

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			char c; cin >> c;
			if (c == '.') grid[i][j] = 1;
			else grid[i][j] = -MX;
		}
	}

	// Ver horizontal
	int mx_horizontal = 0;
	for (int i = 0; i < d; i++) {
		int mx_sum = 0, curr = 0;
		// Aplicar Kadane
		for (int j = 0; j < d; j++) {
			curr = max(grid[i][j], curr + grid[i][j]);
			mx_sum = max(mx_sum, curr);
		}
		mx_horizontal = max(mx_horizontal, mx_sum);
	}

	// Ver vertical
	int mx_vertical = 0;
	for (int j = 0; j < d; j++) {
		int mx_sum = 0, curr = 0;
		// Aplicar Kadane
		for (int i = 0; i < d; i++) {
			curr = max(grid[i][j], curr + grid[i][j]);
			mx_sum = max(mx_sum, curr);
		}
		mx_vertical = max(mx_vertical, mx_sum);
	}

	cout << max(mx_vertical, mx_horizontal) << "\n";
}

void p2() {
	int d; cin >> d;
	vector<vector<int>> grid(d, vector<int>(d));

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			char c; cin >> c;
			if (c == '.') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}

	vector<vector<int>> DP(d, vector<int>(d));
	// Fill dp
	for (int i = 0; i < d; i++) DP[0][i] = grid[0][i]; 
	for (int i = 0; i < d; i++) DP[i][0] = grid[i][0];
	for (int i = 1; i < d; i++) {
		for (int j = 1; j < d; j++) {
			if (grid[i][j] == 0) DP[i][j] = 0;
			else {
				DP[i][j] = min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1])) + 1; // Find intersection
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			ans = max(ans, DP[i][j] * DP[i][j]);
		}
	}

	cout << ans << "\n";
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