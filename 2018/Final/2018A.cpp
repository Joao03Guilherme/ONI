# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll dp[20][2048][2][2]; // No of digits, Digits used (bitmask), leading_zeroes, tight
int k;

ll solve(string& num, int n_digits, int bitmask, int leading_zeroes, int tight) {
	if (__builtin_popcount(bitmask) > k) return 0; 
	if (n_digits == 0) return 1;

	if (dp[n_digits][bitmask][leading_zeroes][tight] != -1) 
		return dp[n_digits][bitmask][leading_zeroes][tight];

	ll ans = 0ll;
	int lb = 0, ub = tight ? (num[num.size() - n_digits] - '0') : 9;
	for (int dig = lb; dig <= ub; dig++) {
		if (dig == 0 && leading_zeroes) {
			ans += solve(num, n_digits-1, 0, 1, tight && (dig == ub));
		}
		else {
			ans += solve(num, n_digits-1, (bitmask|(1<<dig)), (dig == 0) && leading_zeroes, tight && (dig == ub));
		}
	}
	return dp[n_digits][bitmask][leading_zeroes][tight] = ans;
}

int main()
{
    IOS;
    int n; cin >> n;
    while (n--) {
    	ll a, b; cin >> a >> b >> k;
    	string A = to_string(a-1); // a can't be 0
    	string B = to_string(b);

    	memset(dp, -1ll, sizeof(dp));
    	ll ans1 = solve(A, A.size(), 0, 1, 1);
    	memset(dp, -1ll, sizeof(dp));
    	ll ans2 = solve(B, B.size(), 0, 1, 1);

    	cout << ans2 - ans1 << "\n";
    }
    return 0;
}