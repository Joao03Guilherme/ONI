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
	int n; ll z; cin >> n >> z;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; pq.push(x);
	}

	ll soma = 0;
	int cnt = 0;

	while (soma < z) {
		soma += pq.top(); pq.pop();
		cnt++;
	}

	cout << cnt << "\n";
	return 0;
}
