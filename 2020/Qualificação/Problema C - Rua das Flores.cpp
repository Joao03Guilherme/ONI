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

// Sliding window
void p1()
{
    int n, k; cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll soma = 0;
    for (int i = 0; i < k; i++) {
        soma += v[i];
    }

    ll ans = soma;
    for (int i = k; i < n; i++) {
        soma += v[i] - v[i-k];
        ans = min(ans, soma);
    }
    cout << ans << "\n";
}

ll n_subarrays_soma_maxima_x(ll x, vi& arr)
{
    // Se o segmento de i até x_i tem soma <= K, então o segmento i+1 até x_i também tem soma <= K (lógicamente)
    // Vamos começar com o "índice - 1", para obtermos o número de segmentos (um único elemento também é um segmento)
    int xi = -1;
    ll P = 0; // Soma parcial
    ll ans = 0;
    for (int i = 0; i < (int)arr.size(); i++) { // Calcular índice máximo do segmento começado em i, tal que soma <= X
        xi = max(-1, xi-1); // Começamos no xi!, mas para contemplar o caso único, subtraímos por 1

        if (i > 0)
            P -= arr[i]; // Decrementar o elemento anterior (mover o ponteiro esquerdo da window)

        while(i+xi+1 < (int)arr.size() && P + arr[i+xi+1] <= x) {
            P += arr[i+xi+1];
            xi++;
        }

        ans += xi+1;
    }
    debug(ans);
    return ans;
}

void p2()
{
    int n;
    ll k;
    cin >> n >> k;

    vi v(n);
    ll S = 0; // Soma máxima
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        S += v[i];
    }

    // Fazer pesquisa binária pelos segmentos
    ll l=0, r=S;
    while(l < r) {
        ll mid = (l+r)/2;
        if (n_subarrays_soma_maxima_x(mid, v) < k) { // Avançamos para a segunda metade
            l = mid+1;
        }
        else {
            r = mid;
        }
        debug(mid);
    }
    cout << l << "\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p==1) p1();
    else if (p==2) p2();
    return 0;
}

/*
	COISAS A TOMAR ATENÇÃO
    - Overflow
    - Prestar atenção aos limites do problema
    - É preciso apenas determinar um número ou a resposta "toda"
    - Utilizar Sievo para primos
    - Precomputação
*/
