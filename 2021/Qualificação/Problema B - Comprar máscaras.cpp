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

void p1(ll n, ll m) {
	vi a(n); for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	cout << (ll) accumulate(a.begin(), a.begin()+m, 0ll) << "\n";
}

// Solução complexidade mlog(n)
/*
void p2(ll n, ll m) {
	vector <ll> a(n); for (ll& x : a) cin >> x;
	multiset <ll> st;
	for (int i = 0; i < n; i++) st.insert(a[i]);
	
	ll ans = 0;
	while(m--) {
		auto itr = st.begin(); st.erase(itr);
		ans += *itr;
		st.insert(*itr + 1ll);
	}
	cout << ans << "\n"; 
}
*/

// Solução complexidade O(n) + O(dos ciclos)
// A ideia é dividir em dois casos:
// -> É possível completar a diferença entre elementos seguidos (verificar com prog. aritmética)
// -> Se não for possível, ver quantas iterações sobre i é preciso fazer 
void p2(ll n, ll m) {
	vector<ll> a(n); for (ll& x : a) cin >> x;
	sort(a.begin(), a.end());

	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		int diff = min(m, (a[i] - a[i-1]) * i);

		if (diff == m) { // Não podemos avançar
			int iterations = m/i;
			m -= iterations * i;
			ans += ((a[i-1] + a[i-1] + iterations - 1) / 2.0) * iterations * i;
			
			a[i-1] += iterations;
			ans += m*a[i-1]; // Resto
			m = 0;
		}
		else {
			ll d = a[i] - a[i-1];
			ans += ((a[i-1] + a[i] - 1) / 2.0) * (a[i] - a[i-1]) * i; 
			m -= (a[i] - a[i-1]) * i;
		}
		
		if (m <= 0) break;
	}

	if (m > 0) {
		int iterations = m/n;
		m -= iterations * n;
		ans += ((a[n-1] + a[n-1] + iterations - 1) / 2.0) * iterations * n;

		a[n-1] += iterations;
		ans += m*a[n-1]; // Resto
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
    ll p; cin >> p;
    ll n, m; cin >> n >> m;

    if (p == 1) p1(n, m);
    else p2(n, m);
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