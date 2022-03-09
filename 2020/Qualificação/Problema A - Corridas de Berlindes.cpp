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

void p1()
{
    // Fazer tabela com a velocidade e agilidade dos berlindes
    bool t[11][11]; memset(t, false, sizeof(t));
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v, a; cin >> v >> a;
        if (!t[v][a]) {
            ans++;
            t[v][a] = true;
        }
    }
    cout << ans << "\n";
}

void p2()
{
    vector <pii> p;
    // Tabela com a velocidade
    int t[11][11]; memset(t, 0, sizeof(t));
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int v, a; cin >> v >> a;
        t[v][a]++;
        p.pb({v, a});
    }

    int ans = 0;
    for (auto x : p) {
        int curr = 0;
        for (int i = 1; i < x.first; i++) {
            for (int j = 1; j < x.second; j++) {
                curr += t[i][j];
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else p2();
    return 0;
}
