// INFO:
// https://stackoverflow.com/questions/64326998/omn-algorithm-to-check-if-a-directed-graph-is-unilaterally-connected

# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 1'000'001;
const int UNVISITED = -1;

int id = 0;
int n, m;
int ids[MX];
int low[MX];
int sz[MX];
int DP[MX];
bool on_stack[MX];
stack<int> st;
vector<vector<int>> adj;
vector<vector<int>> DAG;

// START TARJAN ALGO
void dfs(int curr) {
    st.push(curr);
    on_stack[curr] = true;
    ids[curr] = low[curr] = id++;

    for (int x : adj[curr]) {
        if (ids[x] == UNVISITED) dfs(x);
        if (on_stack[x]) low[curr] = min(low[curr], low[x]);
    }

    if (ids[curr] == low[curr]) {
        while(true) {
            int node = st.top(); st.pop();
            on_stack[node] = false;
            low[node] = ids[curr];
            if (node == curr) break;
        }
    }
}

void findSccs() {
    for (int i = 0; i < n; i++) {
        ids[i] = UNVISITED;
        low[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (ids[i] == UNVISITED){
            dfs(i);
        }
    }
}
// END TARJAN ALGO

// START 
int findMaxSize(int i) {
    if (DP[i] != -1) return DP[i];
    DP[i] = sz[i]; // Base size of connected component, when no other component is added
    for (int x : DAG[i]) {
        DP[i] = max(DP[i], findMaxSize(x) + sz[i]);
    }
    return DP[i];
}
// END

int main() 
{
    IOS;
    int g; cin >> g; // Useless
    cin >> n >> m;
    adj = vector<vector<int>> (n);
    DAG = vector<vector<int>> (n);

    while(m--) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
    }

    // Find SCCS
    findSccs();

    // Build DAG
    memset(sz, 0, sizeof(sz));
    for (int i = 0; i < n; i++) sz[low[i]]++;
    for (int i = 0; i < n; i++) {
        for (int x : adj[i]) {
            if (low[i] != low[x]) { // Different components
                DAG[low[i]].pb(low[x]);
            }
        }
    }

    int ans = 0;
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < n; i++) {
        if (DP[low[i]] == -1) { // Max size was not determined yet
            findMaxSize(low[i]);
            ans = max(ans, findMaxSize(low[i]));
        }
    }

    cout << ans << "\n";
    return 0;
}