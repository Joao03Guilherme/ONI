# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll dp[20][20][2][2]; // N_digitos, Ordem_azarado, Leading Zeros, Tight

ll solve(string& num, string& azarado, int n_digits, int n_azarado, int leading_zeros, int tight) {
	if (n_azarado == (int) azarado.size()) return 0;
	if (n_digits == 0) return 1;
	if (dp[n_digits][n_azarado][leading_zeros][tight] != -1)
		return dp[n_digits][n_azarado][leading_zeros][tight];

	ll ans = 0ll;
	int lb = 0, ub = tight ? (num[num.size() - n_digits] - '0') : 9;
	for (int dig = lb; dig <= ub; dig++) {
		if (leading_zeros && dig == 0) {
			ans += solve(num, azarado, n_digits-1, 0, leading_zeros, tight && (dig == ub));
		} else if ((azarado[n_azarado] - '0') == dig) {
			ans += solve(num, azarado, n_digits-1, n_azarado+1, leading_zeros && (dig==0), tight && (dig == ub));
		} else if ((azarado[0] - '0') == dig) {
			ans += solve(num, azarado, n_digits-1, 1, leading_zeros && (dig==0), tight && (dig == ub));
		} else {
			ans += solve(num, azarado, n_digits-1, 0, leading_zeros && (dig==0), tight && (dig == ub));
		}
	}
	return dp[n_digits][n_azarado][leading_zeros][tight] = ans;
}

int main()
{
    IOS;
    ll a, q; cin >> a >> q;
    while(q--) {
    	memset(dp, -1, sizeof(dp));
    	ll n; cin >> n;
    	string A = to_string(a);
    	string N = to_string(n);

    	ll ans = solve(N, A, N.size(), 0, 1, 1);
    	cout << ans - 1ll << "\n";
    }
    return 0;
}