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

const int MX = 131072; // 2^17
bool cond[MX]; // Diz se o número x cumpre a condição da parte

void sievo_de_erastotenes()
{
    for (int i = 0; i < MX; i++) cond[i] = true;
    for (int i = 2; i < MX; i++) {
        if (cond[i]) {
            // Começar o Sievo na sqrt (não é na sqrt pq dá overflow, mas deveria ser)
            int c = 2*i;
            while(c < MX) {
                cond[c] = false;
                c += i;
            }
        }
    }
}

void potencias_base_dois_menos_um()
{
    for (int i = 0; i < MX; i++) cond[i] = false;
    int p = 2;
    while (p < MX) {
        cond[p-1] = true;
        p *= 2;
    }
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) {potencias_base_dois_menos_um();}
    else if (p == 2) {sievo_de_erastotenes();}

    int n; cin >> n;
    int l = 1, r = n;
    while (r > l) {
        if (cond[l+r]) {
            for (int i = 0; i <= (r-l)/2; i++) {
                cout << l+i << " " << r-i << "\n";
            }
            r = l-1;
            l = 1;
        }
        else {
            l++;
        }
    }
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
