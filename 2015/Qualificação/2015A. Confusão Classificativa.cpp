# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

struct contestant {
	string name;
	int points;
};

bool cmp(const contestant& a, const contestant& b) {
	if (a.points == b.points) {
		return a.name < b.name;
	}
	return a.points > b.points;
}

int main() 
{
	IOS;
	int n, p; cin >> n >> p;
	vector<contestant> contestants;
	for (int i = 0; i < n; i++) {
		contestant c;
		cin >> c.name;

		int points = 0;
		for (int j = 0; j < p; j++) {
			int x; cin >> x; points += x;
		}
		c.points = points;

		contestants.pb(c);
	}	

	sort(contestants.begin(), contestants.end(), cmp);
	for (contestant c : contestants) {
		cout << c.name << " " << c.points << "\n";
	}

	return 0;
}