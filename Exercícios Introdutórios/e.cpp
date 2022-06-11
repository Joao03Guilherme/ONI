# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

struct plane {
	int x, y, s=0;
	pair<int, int> prev_pos;
};

struct cloud {
	int x, y;
};

pair<int, int> calculate_coords(plane p) {
	if (p.s == 0) p.x++;
	else if (p.s == 1) p.y--;
	else if (p.s == 2) p.x--;
	else p.y++;
	return {p.x, p.y};
}

int main() 
{
	IOS;
	int n, m, k; cin >> n >> m >> k;
	vector<plane> planes;
	vector<cloud> clouds;

	for (int i = 0; i < n; i++) {
		plane p; cin >> p.x >> p.y;
		p.prev_pos = {p.x, p.y};
		planes.pb(p); 
	}

	for (int i = 0; i < m; i++) {
		cloud c; cin >> c.x >> c.y;
		clouds.pb(c);
	}

	vector<vector<bool>> intersections(n, vector<bool> (n, false));

	while (k--) {
		// Update positions
		for (int i = 0; i < n; i++) {
			pair<int, int> new_coords = calculate_coords(planes[i]);

			// Check for clouds
			bool flag = false;
			for (cloud c : clouds) {
				if (c.x == new_coords.first && c.y == new_coords.second) flag = true;
				if (flag) break;
			}

			if (flag) planes[i].s = (planes[i].s + 1) % 4;
			else {
				planes[i].prev_pos.first = planes[i].x;
				planes[i].prev_pos.second = planes[i].y;
				planes[i].x = new_coords.first; planes[i].y = new_coords.second;
			}
		}

		// Calculate intersections
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (planes[i].x == planes[j].x && planes[i].y == planes[j].y) {
					intersections[i][j] = intersections[j][i] = true;
				}
				else { // Movem-se em direções opostas
					if (planes[i].x == planes[j].x) {
						if (planes[i].y == planes[j].prev_pos.second && planes[j].y == planes[i].prev_pos.second)
							intersections[i][j] = intersections[j][i] = true;
					}
					else if (planes[i].y == planes[j].y) {
						if (planes[i].x == planes[j].prev_pos.first && planes[j].x == planes[i].prev_pos.first)
							intersections[i][j] = intersections[j][i] = true;
					}
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (intersections[i][j]) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
