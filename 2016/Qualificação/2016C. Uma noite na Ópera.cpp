# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1'000'000;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 1'000'001;

struct node {
	ll sum, maxprefix, maxsuffix, maxsum;
};

node combine(const node& a, const node& b) {
	node res;
	res.sum = a.sum + b.sum;
	res.maxprefix = max(a.maxprefix, b.maxprefix + a.sum);
	res.maxsuffix = max(a.maxsuffix + b.sum, b.maxsuffix);
	res.maxsum = max( (a.maxsuffix + b.maxprefix), max(a.maxsum, b.maxsum) );
	return res;
}

int n, q;
vector<ll> arr;
vector<node> segTree(MX*4);

void build(int v, int low, int high) {
	if (low == high) {
		segTree[v] = {arr[low], arr[low], arr[low], arr[low]};
		return;
	}

	int mid = (low + high) / 2;
	build(v*2, low, mid);
	build(v*2+1, mid+1, high);

	segTree[v] = combine(segTree[v*2], segTree[v*2+1]);
}

void update(int v, int low, int high, int index, ll new_val) {
	if (index > high || index < low) return;
	if (high == low) {
		segTree[v] = {new_val, new_val, new_val, new_val};
		return;
	}

	int mid = (low + high) / 2;
	update(v*2, low, mid, index, new_val);
	update(v*2+1, mid+1, high, index, new_val);

	segTree[v] = combine(segTree[v*2], segTree[v*2+1]); 
}

int main() 
{
	IOS;
	cin >> n >> q;
	string s; cin >> s;
	for (char c : s) {
		if (c == '0') arr.pb(1ll);
		else arr.pb((ll)-INF);
	}

	build(1, 0, n-1);
	while (q--) {
		char c; cin >> c;
		if (c == 'Q') cout << max(0ll, segTree[1].maxsum) << "\n";
		else {
			int k; cin >> k; k--;
			if (c == 'P') {
				update(1, 0, n-1, k, (ll)-INF);
			} else {
				update(1, 0, n-1, k, 1ll);
			}
		}
	}
	//
	return 0;
}