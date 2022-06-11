#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n; cin >> m >> n;
    vector<int> v(m); for (int& x : v) cin >> x;
    sort(v.begin(), v.end()); int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (cnt >= m) break;
        if (v[cnt] >= i) cnt++;
    }

    if (cnt == m) cout << "1\n";
    else cout << "0\n";
	return 0;
}

