# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll grid(ll i, ll j) {
	return (i + j - 1) * (i + j - 2) / 2 + j;
}

// Vide: https://math.stackexchange.com/questions/1569860/how-to-find-formula-for-recursive-sequence-sum
ll col_sum(ll i, ll j, ll h) { // Isto é overkill, não é preciso tanto
	ll diff = grid(i+1, j) - grid(i, j);
	ll ans = grid(i, j)*(h) + diff * (h-1)*(h) / 2 + (h-2)*(h-1)*(h)/6; 
	return ans;
}

int main() 
{
	IOS;
	int n; cin >> n;
	while(n--) {
		ll a, b; cin >> a >> b;
		ll n1 = floor((1.0 + sqrt(8.0*a - 7.0)) / 2.0);
		ll n2 = floor((1.0 + sqrt(8.0*b - 7.0)) / 2.0);
		ll j1 = a - (ll) n1 * (n1 - 1) / 2;
		ll j2 = b - (ll) n2 * (n2 - 1) / 2;

		ll h = abs(n1-j1 - (n2-j2)) + 1;

		ll ans = 0; 
		for (ll x = 0; x <= abs(j1-j2); x++) {
			ans += col_sum(n1-j1+1, j1+x, h);
		}
		cout << ans << "\n";
	}
	return 0;
}