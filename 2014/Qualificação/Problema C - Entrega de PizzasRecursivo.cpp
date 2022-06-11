# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// Implementar solução recursiva
int n, ans = INF; 
vi c;

int calculate_cost(vector<int> path) {
	int ans = 0, curr = 0, last = 0;
	for (int x : path) {
		curr += abs(last - x);
		ans += curr;
		last = x;
	}
	return ans;
}

void f(int pos, int l, int r, vector<int> path) {
	if (l == 0 && r == n) {ans = min(ans, calculate_cost(path));}
	else {
		if (l-1 >= 0) { // Go left
			path.pb(c[l-1]);
			f(l-1, l-1, r, path);
			path.pop_back(); // Backtrack
		}

		if (r+1 <= n) { // Go right
			path.pb(c[r+1]);
			f(r+1, l, r+1, path);
			path.pop_back(); // Backtrack
		}
	}
}

int main() 
{
	IOS;
	cin >> n; c.resize(n);
	for (int& x : c) cin >> x;
	c.pb(0); sort(c.begin(), c.end());

	int p = 0; // Posição da loja
	while (p < n+1 && c[p] != 0) {
		p++;
	}

	vector<int> path;
	f(p,p,p,path);
	cout << ans << "\n";
	return 0;
}