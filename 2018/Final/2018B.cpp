# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll n, k, q; 
vector<ll> p;

bool f(ll t) {
	ll acum = 0ll; // Número de problemas já verificados
	for (int i = 0; i < n; i++) {
		acum += (t - q * (i + k - acum)) / (p[i] - q); 
		if (acum >= k) return true;
	}
	return false;
}

// Binary search for the answer
int main()
{
    IOS;
    cin >> n >> k >> q;
    p.resize(n); for (ll& x : p) cin >> x;

    ll low = -1, high = 1e18;
    while (low +1 < high) {
    	ll mid = (low + high) / 2;
    	if (f(mid)) high = mid;
    	else low = mid;
    }
    cout << high << "\n";
    return 0;
}