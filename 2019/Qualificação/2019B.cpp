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
    int n, m; cin >> n >> m;
    vi d(m); for (int& x : d) cin >> x;
    sort(d.begin(), d.end());

    int Q; cin >> Q;
    vi q(Q); for (int& x : q) cin >> x;

    for (int x : q) {
    	// Pesquisa binária
    	// Invariance
    	// d[l] < x
    	// d[r] >= x
    	// Queremos saber todos os participantes
    	// No range r-->n
    	int l = -1, r = m;
    	while (r > l+1) {
    		int mid = (l+r)/2;
    		if (d[mid] < x) l = mid;
    		else r = mid; 
    	}

    	cout << m - r << "\n";
    }
    return 0;
}