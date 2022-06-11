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

struct node {
    ll sum, bestsum, prefix, sufix;
};

node tree[MX*4];
ll lazy[MX*4];

node combine(node n1, node n2) {
    node res;
    res.sum = n1.sum + n2.sum;
    res.bestsum = max(n1.bestsum, max(n2.bestsum, n1.sufix + n2.prefix));
    res.prefix = max(n1.prefix, n1.sum + n2.prefix);
    res.sufix = max(n2.sufix, n2.sum + n1.sufix);
    return res;
}

void build(int i, int low, int high) {
    if (low == high) {
        tree[i] = node{1, 1, 1, 1};
        return;
    } 

    int mid = (low + high) / 2;
    build(i*2, low, mid);
    build(i*2+1, mid+1, high);
    tree[i] = combine(tree[i*2], tree[i*2+1]);
}

void update(int i, int low, int high, int u_low, int u_high, ll val) { 
    if (lazy[i]) {
        ll add = (high - low + 1) * lazy[i];
        tree[i].sum += add;
        tree[i].bestsum += add;
        tree[i].prefix += add;
        tree[i].sufix += add;

        if (low != high) {
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (low > u_high || high < u_low || low > high) return;
    if (low >= u_low && high <= u_high) {
        ll add = (high - low + 1) * val;
        tree[i].sum += add;
        tree[i].bestsum += add;
        tree[i].prefix += add;
        tree[i].sufix += add;

        if (low != high) {
            lazy[i*2] += val;
            lazy[i*2+1] += val;
        }
        return;
    }

    int mid = (low + high) / 2;
    update(i*2, low, mid, u_low, u_high, val);
    update(i*2+1, mid+1, high, u_low, u_high, val);
    tree[i] = combine(tree[i*2], tree[i*2+1]);
}

int main() 
{
    IOS;
    int n, k, p; cin >> n >> k >> p;
    memset(lazy, 0, sizeof(lazy));
    build(1, 0, n-1);

    map<int, vector<vector<int>>> obras; // Time, Type, Start, End
    for (int i = 0; i < k; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        obras[c].pb({0, a, b}); // 0 -> Start obras
        obras[d+1].pb({1, a, b}); // 1 -> End obras
    }

    map<int, ll> mp; mp[-1] = n;
    for (pair<int, vector<vector<int>>> obra : obras) {
        int time = obra.first;
        for (vector<int> seg : obra.second) {
            if (seg[0] == 0) {
                update(1, 0, n-1, seg[1], seg[2], -INF);
            } else {
                update(1, 0, n-1, seg[1], seg[2], INF);
            }
        }
        mp[time] = tree[1].bestsum;
    }

    for (int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        ll ans = 0ll;

        auto bound = mp.lower_bound(a);
        if (bound == mp.end()) ans = n;
        else if (bound->first != a) bound--;

        while (bound != mp.end()) {
            if (bound->first <= b) {
                ans = max(ans, bound->second);
            } else break;
            bound++;
        } 
        cout << ans << "\n";
    }
    return 0;
}