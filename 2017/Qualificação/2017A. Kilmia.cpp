# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int N, B, I; cin >> N >> B >> I;
    vector<bool> tesouros;
    vector<int> instrucoes;

    for (int i = 0; i < N; i++) {
    	char s; cin >> s;
    	if (s == 'T') tesouros.pb(true);
    	else tesouros.pb(false);
    }

    for (int i = 0; i < I; i++) {
    	string s; int p; cin >> s >> p;
    	if (s == "D") instrucoes.pb(p);
    	else instrucoes.pb(-p);
    }

    int mn, mx; mn = mx = B;
    for (auto x : instrucoes) {
        B = B + x;
        mn = min(mn, B);
        mx = max(mx, B);
    }

    mx--; mn--; int cnt = 0;
    for (int i = mn; i <= mx; i++) {
        if (tesouros[i]) cnt++;
    }

    cout << cnt << "\n";
}