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
    int n; cin >> n;
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for (const auto& x : mp) {
        ans += x.second*(x.second-1)/2; // nCr2
    }
    cout << ans << "\n";
}

void p2()
{
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vi dir(n, n);
    vi esq(n, -1);
    // Processar direita
    stack <int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {s.push(i); continue;}
        if (v[s.top()] > v[i] ) {s.push(i); continue;}
        while(!s.empty() && v[i] >= v[s.top()]) {
            dir[s.top()] = i; s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) s.pop();
    // Processar esquerda
    for (int i = n-1; i >= 0; i--) {
        if (s.empty()) {s.push(i); continue;}
        if (v[s.top()] > v[i] ) {s.push(i); continue;}
        while(!s.empty() && v[i] >= v[s.top()]) {
            esq[s.top()] = i; s.pop();
        }
        s.push(i);
    }

    ll max_ph = n;
    ll len_max_ph = 1;
    for (int i = 0; i < n; i++) {
        ll ph = min(abs(i-dir[i]) - 1, abs(i-esq[i]) - 1);
        max_ph += ph;
        len_max_ph = max(len_max_ph, ph*2+1);
    }
    cout << len_max_ph << " " << max_ph << "\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p==1) p1();
    else p2();
    return 0;
}
