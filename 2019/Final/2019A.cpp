# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const int MX = 100'001;
const long long INFLL = (ll)INF * (ll)INF;

struct node {
	ll sum, maxprefix, maxsuffix, maxsum; 
};

// Ideia: Criar árvore de segmentos 
vector<node> segTree;
vector<ll> s;

// https://codeforces.com/blog/entry/17780
// https://pastebin.com/9eZDTPdi
node combine(const node& a, const node& b) {
	node res;
	res.sum = a.sum + b.sum;
	res.maxprefix = max(a.maxprefix, b.maxprefix + a.sum);
	res.maxsuffix = max(a.maxsuffix + b.sum, b.maxsuffix);
	res.maxsum = max( (a.maxsuffix + b.maxprefix), max(a.maxsum, b.maxsum) );

	return res;
}

void buildTree(int v, int low, int high) {
	if (low == high) {
		segTree[v] = {s[low], s[low], s[low], s[low]};
		return;
	}

	int mid = (low + high) / 2;
	buildTree(v*2, low, mid);
	buildTree(v*2 + 1, mid+1, high);

	segTree[v] = combine(segTree[v*2], segTree[v*2+1]);
}

void update(int v, int tl, int tr, int x, int val) {
    if(x < tl || tr < x) return;
 
    if(tl==tr) {
        segTree[v] = { val, val, val, val };
        return;
    }
 
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, x, val);
    update(2*v+1, tm+1, tr, x, val);
 
    segTree[v] = combine(segTree[2*v], segTree[2*v+1]);
}

// Query operation always returns segTree[1]

int main() 
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t; 
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> updates; s.resize(MX); 

		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (s[i] < 0) updates.pb(i);
		}

		segTree.resize(4*MX);
		buildTree(1, 0, n-1);

		int r = 0;
		for (; r < min(k, (int)updates.size()); r++) {
			update(1, 0, n-1, updates[r], abs(s[updates[r]]));
		}
		ll res = max(0ll, segTree[1].maxsum);

		while(r < (int)updates.size()) {
			update(1, 0, n-1, updates[r], abs(s[updates[r]]));
			update(1, 0, n-1, updates[r-k], s[updates[r-k]]);
			res = max(res, segTree[1].maxsum);
			r++;
		}
		cout << res << "\n";
	}

	return 0;
}