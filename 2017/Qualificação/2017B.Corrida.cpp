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


int N, Q;
vector<vector<int>> points;
set<pair<int, int>> sweep_line;

struct cmp {
	bool operator() (const vector<int> v1, const vector<int> v2) {
		return v1[0] < v2[0];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    IOS;
    cin >> N >> Q; 

    for (int i = 0; i < N; i++) {
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    	int h = abs(y1 - y2);

    	vector<int> v1 = {x1, h, 1};
    	vector<int> v2 = {x2, h, -1};
    	points.pb(v1); points.pb(v2);
    }
    sort(points.begin(), points.end(), cmp());

    int C = 0;
    sweep_line.insert({0,0}); // Dummy value in case x is less than all recorded positions
    for (vector<int> p : points) {
    	int x = p[0], h = p[1], t = p[2];
    	if (t == 1) C += h;
    	else C -= h;

    	auto itr = sweep_line.find({x, 0}); // Update previous value
    	if (itr != sweep_line.end()) sweep_line.erase(itr);

    	sweep_line.insert({x, C});
    }
    
    while (Q--) {
    	int x; cin >> x;
    	auto itr = sweep_line.upper_bound({x, 0});
    	cout << (*itr).second << "\n";
    }
    return 0;
}