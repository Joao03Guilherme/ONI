# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void p1(ll n, ll m) {
	vi a(n); for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	cout << (ll) accumulate(a.begin(), a.begin()+m, 0ll) << "\n";
}

// Solução complexidade mlog(n)
/*
void p2(ll n, ll m) {
	vector <ll> a(n); for (ll& x : a) cin >> x;
	multiset <ll> st;
	for (int i = 0; i < n; i++) st.insert(a[i]);
	
	ll ans = 0;
	while(m--) {
		auto itr = st.begin(); st.erase(itr);
		ans += *itr;
		st.insert(*itr + 1ll);
	}
	cout << ans << "\n"; 
}
*/

// Solução complexidade O(n) 
// A ideia é dividir em dois casos:
// -> É possível completar a diferença entre elementos seguidos (verificar com prog. aritmética)
// -> Se não for possível, ver quantas iterações sobre i é preciso fazer 
void p2(ll n, ll m) {
	vector<ll> a(n); for (ll& x : a) cin >> x;
	sort(a.begin(), a.end());

	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		int diff = min(m, (a[i] - a[i-1]) * i);

		if (diff == m) { // Não podemos avançar
			int iterations = m/i;
			m %= i;
			ans += ((a[i-1] + a[i-1] + iterations - 1) / 2.0) * iterations * i;
			
			a[i-1] += iterations;
			ans += m*a[i-1]; // Resto
			m = 0;
		}
		else { // Podemos avançar e "alisar" a array
			ans += ((a[i-1] + a[i] - 1) / 2.0) * (a[i] - a[i-1]) * i; // a[i-1] + a[i-1] + 1 + ...
			m -= (a[i] - a[i-1]) * i;	// Número de máscaras compradas	
		}
		
		if (m <= 0) break;
	}

	if (m > 0) {
		int iterations = m/n;
		m %= i;
		ans += ((a[n-1] + a[n-1] + iterations - 1) / 2.0) * iterations * n;

		a[n-1] += iterations;
		ans += m*a[n-1]; // Resto
	}
	cout << ans << "\n"; 
}

int main()
{
    IOS;
    ll p; cin >> p;
    ll n, m; cin >> n >> m;

    if (p == 1) p1(n, m);
    else p2(n, m);
    return 0;
}