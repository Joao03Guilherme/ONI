# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

vector<vector<int>> table(11, vector<int>(11, 0));

void p1() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, v; cin >> a >> v;
        table[a][v]++;
    }

    int cnt = 0;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (table[i][j]) cnt++;
        }
    }
    cout << cnt << "\n";
}

void p2() {
    int n; cin >> n;
    vector<pii> b;

    for (int i = 0; i < n; i++) {
        int a, v; cin >> a >> v;
        table[a][v]++;
        b.pb({a, v});
    }

    int ans = 0;
    for (pii berlinde : b) {
        int cnt = 0;
        for (int i = 0; i < berlinde.first; i++) {
            for (int j = 0; j < berlinde.second; j++) {
                cnt += table[i][j];
            }
        }
        ans = max(ans, cnt);
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