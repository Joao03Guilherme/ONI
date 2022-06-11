# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;
 
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
 
int n, d, k;
vector<int> pas;
vector<vector<int>> segTree; // Guarda o valor do node, indice
vector<int> lazy; 
 
void update(int node, int node_low, int node_high, int update_low, int update_high, int val) {
    if (lazy[node]) { // Dar update deste node
        segTree[node][0] += lazy[node];
        if (node_low != node_high) { // Propagar para os filhos
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    if (node_low > node_high || node_low > update_high || node_high < update_low) return;
 
    if (node_low >= update_low && node_high <= update_high) {
        segTree[node][0] += val;
        if (node_low != node_high) {
            lazy[node*2] += val;
            lazy[node*2 + 1] += val; 
        }
        return;
    }
 
    int mid = (node_low + node_high) / 2;
    update(node*2, node_low, mid, update_low, update_high, val);
    update(node*2+1, mid+1, node_high, update_low, update_high, val);
 
    if (segTree[node*2][0] < segTree[node*2+1][0]) segTree[node] = segTree[node*2];
    else segTree[node] = segTree[node*2+1];
}
 
vector<int> query(int node, int node_low, int node_high, int query_low, int query_high) {
    if (lazy[node]) {
        segTree[node][0] += lazy[node];
        if (node_low != node_high) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    if (node_low > node_high || node_low > query_high || node_high < query_low) return vector<int>(2, INF);
    if (node_low >= query_low && node_high <= query_high) return segTree[node];
 
    int mid = (node_low + node_high) / 2;
    vector<int> a = query(node*2, node_low, mid, query_low, query_high);
    vector<int> b = query(node*2+1, mid+1, node_high, query_low, query_high);
 
    if (a[0] < b[0]) return segTree[node] = a;
    return segTree[node] = b;
}
 
// Passa em 100% dos testcases
int main() 
{
    IOS;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; pas.pb(x);
    }
 
    vector<int> esq(n), dir(n);
    esq[0] = 0; dir[n-1] = n-1;
 
    // Calcular pá mais à esquerda da pá atual
    for (int i = 1; i < n; i++) {
        for (int j = esq[i-1]; j <= i; j++) { // Começamos a contar da pá mais à esquerda da anterior
            if (abs(pas[i] - pas[j]) <= d) {
                esq[i] = j; break;
            }
        }
    }
 
    // Calcular pá mais à direita
    for (int i = n-2; i >= 0; i--) {
        for (int j = dir[i+1]; j >= i; j--) {
            if (abs(pas[i] - pas[j]) <= d) {
                dir[i] = j; break;
            }
        }
    }
 
    vector<int> degree(n, 0);
    vector<bool> valid(n, true);
    for (int i = 0; i < n; i++) degree[i] = dir[i] - esq[i];
 
    // Criar árvore de segmentos
    int p = n;
    while (__builtin_popcount(p) != 1) {
        p++; degree.pb(INF);
    }
 
    segTree.resize(2*p, vector<int>(2));
    lazy.resize(2*p);
    for (int i = 0; i < p; i++) { // Adicionar folhas
        segTree[p+i][0] = degree[i];
        segTree[p+i][1] = i;
        lazy[p+i] = 0;
    }
 
    for (int i = p-1; i > 0; i--) {
        lazy[i] = 0;
        if (segTree[i*2][0] < segTree[i*2 + 1][0]) {
            segTree[i] = segTree[i*2];
        }
        else {
            segTree[i] = segTree[i*2 + 1];
        }
    }
 
    bool flag = true;
    while (flag) {
        flag = false;
        vector<int> mn = query(1, 0, p-1, 0, p-1);
        if (mn[0] < k) {
            flag = true;
            valid[mn[1]] = false;
            update(1, 0, p-1, mn[1], mn[1], INF);
            update(1, 0, p-1, esq[mn[1]], dir[mn[1]], -1);
        }
    }
 
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (valid[i]) ans.pb(i+1);
    }
 
    int n = ans.size();
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        if (i == n-1) cout << ans[i] << "\n";
        else cout << ans[i] << " ";
    }
    //
 
    return 0;
}