# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int n, k, t; cin >> n >> k >> t;
    vi a(n); for (int& x : a) cin >> x;

    int dp[n - k + 1]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i < k; i++) {
    	if (a[i] >= t) dp[0]++;
    }

    for (int i = 1; i < n - k + 1; i++) {
    	dp[i] = dp[i-1];
    	if (a[i-1] >= t) dp[i]--;
    	if (a[i+k-1] >= t) dp[i]++;
    }

	int NEEDED = (k+1)/2, ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
    	if (dp[i] >= NEEDED) ans++;
    }

    cout << ans << "\n";
    return 0;
}