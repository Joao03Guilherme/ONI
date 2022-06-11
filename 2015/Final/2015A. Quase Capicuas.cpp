# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;


int K;
ll dp[20][10][10][16][2][2];

ll solve(string& num, int n_digits, int l, int r, int k, int leading, int tight) {
	if (k > K) return 0;
	if (n_digits == 0) return 1;
	if (dp[n_digits][l][r][k][leading][tight] != -1) 
		return dp[n_digits][l][r][k][leading][tight];

	ll ans = 0ll;
	int ub = tight ? (num[num.size() - n_digits] - '0') : 9;
	for (int dig = 0; dig <= ub; dig++) {
		if (leading && dig == 0) 
			ans += solve(num, n_digits-1, 0, 0, 0, leading, tight);
		else {
			if (leading)
				ans += solve(num, n_digits-1, dig, dig, 0, 0, tight && dig == ub);
			else 
				ans += solve(num, n_digits-1, l, dig, dig == l ? k : k+1, 0, tight && dig == ub);
		} 
	}
	return dp[n_digits][l][r][k][leading][tight] = ans;
}

int main()
{
    IOS;
    int p; cin >> K >> p;
    while (p--) {
    	int n; cin >> n;
    	ll l = 0, r = 1e15 + 1;
    	while (l + 1ll < r) {
    		memset(dp, -1, sizeof(dp));
    		ll mid = (l + r) / 2;
    		string num = to_string(mid);
    		cout << solve(num, num.size(), 0, 0, 0, 1, 1) << "\n";
    		break;

    	}
    }
    return 0;
}

