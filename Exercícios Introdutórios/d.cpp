#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') cnt = 0;
            else cnt++;
            mx = max(mx, cnt);
        }
        ans = max(ans, mx);
    }

    if (ans >= k) cout << "1\n";
    else cout << "0\n";
	return 0;
}

