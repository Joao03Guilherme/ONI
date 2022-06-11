#include <bits/stdc++.h>
using namespace std;

const int mod = 12345;

int main()
{
    int n; cin >> n;
    vector<int> g(n);
    for (int& x : g) {cin >> x; x++;}

    int ans = 1;
    for (int x : g) {
        ans = ((ans % mod) * (x % mod)) % mod;
    }

    cout << ans - 1 << "\n";
	return 0;
}

