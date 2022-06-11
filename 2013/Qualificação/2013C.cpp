# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int n, ans = 0;
vector<int> a;

int main() 
{
	IOS;
	cin >> n; a.resize(n);
	for (int& x : a) cin >> x;

	vector<int> dp(n, 1); 
	for (int i = 1; i < n; i++) {
		for (int j = i - a[i]; j >= 0; j--) {
			if (abs(i-j) < a[j]) continue;
			dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}