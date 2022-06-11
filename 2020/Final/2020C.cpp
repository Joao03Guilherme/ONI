# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// O maior declive está sempre entre pontos concutivos, D(1, 2), D(2, 3)...
void p1() {
	int n, l; cin >> n >> l;
	vector<int> a(n); for (int& x : a) cin >> x;

	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans = max(ans, abs(a[i] - a[i-1]));
	} 
	cout << ans << "\n";
} 

void p2() {
	
	;
}

int main() 
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int p; cin >> p;
	if (p == 1) p1();
	else p2();
	return 0;
}