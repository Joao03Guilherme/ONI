# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

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
