# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 3'003;

int n; 
vector<int> c, seq_esq, seq_dir;
vector<vector<vector<int>>> dp(2, vector<vector<int>>(MX, vector<int>(MX, INF)));
int n_total_esq, n_total_dir;

int f(int s, int n_esq, int n_dir) {
	if (dp[s][n_esq][n_dir] != INF) return dp[s][n_esq][n_dir];
	if (n_dir >= n_total_dir && n_esq >= n_total_esq) return 0;

	if (n_esq < n_total_esq) { // Can go left
		dp[0][n_esq][n_dir] = abs(seq_esq[n_esq] - seq_esq[n_esq-1]) * (n_total_esq+n_total_dir - n_esq-n_dir) + f(0, n_esq+1, n_dir);
		dp[1][n_esq][n_dir]	= abs(seq_esq[n_esq] - seq_dir[n_dir-1]) * (n_total_esq+n_total_dir - n_esq-n_dir) + f(0, n_esq+1, n_dir);		
	} 

	if (n_dir < n_total_dir) { // Can go right
		dp[0][n_esq][n_dir] = min(dp[0][n_esq][n_dir], abs(seq_dir[n_dir] - seq_esq[n_esq-1]) * (n_total_esq+n_total_dir - n_esq-n_dir) + f(1, n_esq, n_dir+1)); 
		dp[1][n_esq][n_dir] = min(dp[1][n_esq][n_dir], abs(seq_dir[n_dir] - seq_dir[n_dir-1]) * (n_total_esq+n_total_dir - n_esq-n_dir) + f(1, n_esq, n_dir+1));
	}
	return dp[s][n_esq][n_dir];
}
	
int main() 
{
	IOS;
	cin >> n; c.resize(n);
	for (int& x : c) cin >> x;

	int i = 0;
	while (i < n && c[i] < 0) {seq_esq.pb(c[i]); i++;}
	while (i < n) {seq_dir.pb(c[i]); i++;}
	reverse(seq_esq.begin(), seq_esq.end());

	n_total_dir = seq_dir.size()+1; n_total_esq = seq_esq.size()+1;
	seq_esq.insert(seq_esq.begin(), 0); seq_dir.insert(seq_dir.begin(), 0);
	dp[0][n_total_esq][n_total_dir] = dp[1][n_total_esq][n_total_dir] = 0;

	cout << f(0,0,0) << "\n";
	//
	return 0;
}