#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int mx = 0, cnt =0;
    for (int x : a) {
        if (x > mx) {
            mx = x; cnt++;
        }
    }
    cout << cnt << "\n";
	return 0;
}
