# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// PROPRIEDADE: (a + b) % k = (a%k + b%k) % k
// Encontrar mods que somem a k ou a 0
void p1(vi& a, vi& b, int x) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		a[i] = a[i] % x;
		b[i] = b[i] % x;
	}

	map<int, int> mpa;
	map<int, int> mpb;
	for (int i = 0; i < n; i++) {
		mpa[a[i]]++;
		mpb[b[i]]++;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) ans += mpb[0];
		else ans += mpb[x - a[i]];
	}

	cout << ans << "\n";
}

// Se têm mods diferentes, não dá para transformar
void p2(vi& a, vi& b, int x) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] % x != b[i] % x) {
			cout << -1 << "\n"; 
			return;
		}
		a[i] = (b[i] - a[i]) / x;
	}
	
	// Agora ficamos com array do tipo --> [0, 3, 2, 3, 0, 0, 4]
	// Objetivo é transformar isto numa array de zeros, usando apenas a decrementação por
	// 1 no range l, r
	// Ou, visto de outra forma, transformar um array de zeros neste array obtido
	// Este exercício é igual a isto: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
	int ans = 0, prev = 0;
	for (int height : a) {
		ans += max(0, height - prev);
		prev = height;
	}
	cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    IOS;
    int p; cin >> p;
    int n, x; cin >> n >> x;
    vi a(n), b(n);
    for (int& k : a) cin >> k;
    for (int& k : b) cin >> k;

    if (p == 1) p1(a, b, x);
    else p2(a, b, x);
    return 0;
}