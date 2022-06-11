# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;


// Não obtém 100 pontos
void p1() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i]) continue;

        queue<int> q; q.push(i); color[i] = 1;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for (int x : adj[curr]) {
                if (color[x] == 0) {
                    color[x] = color[curr] == 1 ? 2 : 1;
                    q.push(x);
                } else if (color[x] == color[curr]) {
                    cout << "não\n";
                    return;
                }
            }
        }
    }
    cout << "sim\n";
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int i) {
    ;
}

void p2() {
    ;
}

int main() 
{
    IOS;
    int p; cin >> p;
    int t; cin >> t;
    while (t--) {
        if (p == 1) p1();
        else p2();
    }
    return 0;
}