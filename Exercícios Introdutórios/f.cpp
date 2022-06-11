#include <bits/stdc++.h>
using namespace std;

#define ll long long int

map<int, ll> mp1;
map<int, ll> mp2;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; mp1[x%2]++;
    }

    int m; cin >> m;
    for (int i = 0; i<  m; i++) {
        int x; cin >> x; mp2[x%2]++;
    }

    ll par = mp1[0] * mp2[0] + mp1[1] * mp2[1];
    ll impar = mp1[0] * mp2[1] + mp1[1] * mp2[0];
    cout << par << " " << impar << "\n";
	return 0;
}

