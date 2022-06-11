#include <bits/stdc++.h>
using namespace std;
const int MX = 1001;

int l, c;
int grid[MX][MX];
int dp[MX][MX];
int cnt[MX*MX];
int M = 0;

void w(int y, int xi, int x) {
	M = max(dp[y][xi] * (x - xi), M);
	cnt[dp[y][xi] * (x - xi)]++;
}

int main() {
    cin >> l >> c;
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            char c; cin >> c;
            if (c == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            dp[i][j] = (i == 0 || grid[i][j] == grid[i-1][j]) ? 1 : dp[i-1][j] + 1;
        }
    }

    for (int y = 0; y < l; y++) {
        stack <int> s;
        for (int x = 0; x < c; x++) {
            int f = x;
            while (!s.empty() && (grid[y][x] == grid[y][x - 1] || dp[y][s.top()] > dp[y][x])) {
                f = grid[y][x] == grid[y][x - 1] ? f : min(f, s.top());
                w(y, s.top(), x); s.pop();
                dp[y][f] = dp[y][x];
            }
            s.push(f);
        }
        while (!s.empty()) {
            w(y, s.top(), c); s.pop();
        }
    }

    cout << M << " " << cnt[M] << "\n";
    return 0;
}