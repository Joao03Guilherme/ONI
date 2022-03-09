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

// Bipartite check
void p1()
{
    int n, m; cin >> n >> m;
    vi adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi cores(n+1, -1);
    queue <int> q; q.push(1); cores[1] = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (int x : adj[curr]) {
            if (cores[x] == -1) {
                cores[x] = 1 - cores[curr];
                q.push(x);
            }
            else if (cores[x] == cores[curr]) {
                cout << "nao" << "\n";
                return;
            }
        }
    }
    cout << "sim" << "\n";
}

void p2()
{
    ;
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p==1) {
        int t; cin >> t;
        while(t--) p1();
    }
    else {
        int t; cin >> t;
        while(t--) p2();
    }
    return 0;
}
