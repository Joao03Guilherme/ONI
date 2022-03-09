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

void p1(int n, int k) {
    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 0; i < n; i++) cout << a[i] + k*b[i] << " ";
    cout << "\n";
}

int sliding_window(vi& a, int k) {
    int n = a.size();
    vi somas(n-k+1);
    for (int i = 0; i < k; i++) somas[0] += a[i];
    for (int i = 1; i < n-k+1; i++) somas[i] = somas[i-1] + a[i+k-1] - a[i-1];
    
    int l = 0, r = k-1, best = 0;
    for (int i = 0; i < n-k+1; i++) {
        if (somas[i] > best) {
            l = i; r = i+k-1; best = somas[i];
        }
    }

    if (best == 0) return 0;
    vi new_a;
    for (int i = 0; i < n; i++) {
        if (i == l) {
            for (int j = 0; j < k; j++) new_a.pb(0);
        }
        if (i >= l && i <= r) new_a.pb(0);
        else new_a.pb(a[i]);
    } 
    a = new_a;
    return best;
}

// Transformar em zeros os utilizados, garantindo uma separação de pelo menos
// k unidades entre eles
void p2(int n, int k) {
    vi a;
    for (int i = 0; i < k; i++) a.pb(0);
    for (int i = 0; i < n; i++) {int x; cin >> x; a.pb(x);}
    for (int i = 0; i < k; i++) a.pb(0);
    cout << sliding_window(a, k) + sliding_window(a, k) + sliding_window(a, k) << "\n";
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int p; cin >> p;
    int n, k; cin >> n >> k;
    if (p == 1) p1(n ,k);
    else p2(n, k);
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
*/
