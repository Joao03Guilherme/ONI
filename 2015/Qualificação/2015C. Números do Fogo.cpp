# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll dp[20][10][2][2][2]; // No of digits, Last digit, Leading zeroes, Tight, Increasing or decreasing

ll count_same_digit(ll L, ll R) 
{
    ll tmp = 0, ans = 0;
    ll n = log10(R) + 1;
 
    for (ll i = 0; i < n; i++) {
        tmp = tmp * 10 + 1;
        for (ll j = 1; j <= 9; j++) {
            if (L <= (tmp * j)
                && (tmp * j) <= R) {
 
                ans++;
            }
        }
    }
    if (L == 0) ans++;
    return ans;
}

ll solve(string& num, int n_digits, int last_digit, int leading_zeroes, int tight, int increasing) {
	if (n_digits == 0) return 1;
	if (last_digit != -1 && dp[n_digits][last_digit][leading_zeroes][tight][increasing] != -1) 
		return dp[n_digits][last_digit][leading_zeroes][tight][increasing];
	
	int lower_bound = 0;
	int upper_bound = tight ? (num[num.size() - n_digits] - '0') : 9; // Left to right 

	ll ans = 0ll;
	for (int dig = lower_bound; dig <= upper_bound; dig++) {
		if (increasing && dig < last_digit && !leading_zeroes) continue;
		if (!increasing && dig > last_digit && !leading_zeroes) continue;
		ans += solve(num, n_digits-1, dig, (dig == 0) && leading_zeroes, tight && (dig == upper_bound), increasing);
	}
	return dp[n_digits][last_digit][leading_zeroes][tight][increasing] = ans;
}

int main() 
{
	IOS;
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		string A = to_string(a-1);
		string B = to_string(b);

		memset(dp, -1, sizeof(dp));
		ll ans1 = solve(A, A.size(), -1, 1, 1, 0); // Decreasing subsequences
		memset(dp, -1, sizeof(dp));
		ll ans2 = solve(B, B.size(), -1, 1, 1, 0);
		ll ans_dec = ans2 - ans1;

		memset(dp, -1, sizeof(dp));
		ans1 = solve(A, A.size(), -1, 1, 1, 1); // Increasing subsequences
		memset(dp, -1, sizeof(dp));
		ans2 = solve(B, B.size(), -1, 1, 1, 1);
		ll ans_inc = ans2 - ans1;

		ll ans = b - a + 1 - ans_dec - ans_inc + count_same_digit(a, b); // Sempre que passamos por número da forma 111 ou 222 há double counting
		cout << ans << "\n";
	}
	return 0;
}