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

	int n, k; cin >> n >> k;
	vector<char> v(n); for (char& x : v) cin >> x;

	vector<int> p(n+1); p[0] = 0; // prefix sum
	for (int i = 1; i < n+1; i++) {
		if (v[i-1] == 'H') {
			p[i] = p[i-1] + 1;
		}
		else {
			p[i] = p[i-1];
		}
	} 

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 'M') {
			int n_homens = p[min(i+k+1, n)] - p[i]; 
			ans += n_homens;
		}
	}

	cout << ans << "\n";
	return 0;
}