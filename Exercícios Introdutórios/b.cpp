#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, l, c; cin >> a >> l >> c;
    int vol = a*l*c;
    if (vol >= 50 && a >= 3) cout << "1\n";
    else cout << "0\n";
	return 0;
}

