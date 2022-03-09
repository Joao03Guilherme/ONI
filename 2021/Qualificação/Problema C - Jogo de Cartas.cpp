# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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

/*
	COISAS A TOMAR ATENÇÃO
    - Overflow
    - Prestar atenção aos limites do problema
    - É preciso apenas determinar um número ou a resposta "toda"
    - Utilizar Sievo para primos
    - Precomputação
    - Inverter o problema
    - Identificar implicações lógicas
    - Problemas com vetores -> O(n)?
    - Manipular fórmulas dadas
    - Há monotonia -> pesquisa binária usa invariance
    - Para números reais, usar setprecision(20)
*/