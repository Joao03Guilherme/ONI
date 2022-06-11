#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> v(n); for (int& x : v) cin >> x;
    sort(v.begin(), v.end());

    vector<int> p(n); p[0] = v[0];
    for (int i = 1; i < n; i++) p[i] = p[i-1] + v[i];

    while (m--) {
        // Do binary search
        // Invariance
        // p[l] <= c
        // p[r] > c
        int x; cin >> x;

        int l = 0, r = n;
        while (l + 1 < r) {
            int m = (l+r) / 2;
            if (p[m] <= x) l = m;
            else r = m;
        }

        cout << l + 1 << "\n";
    }

	return 0;
}

