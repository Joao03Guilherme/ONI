# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int p = 1;
int L, C, D;
vector<vector<int>> grid;
vector<vector<int>> visited;
map <int, int> tower_group;
map <int, int> tower_cost;
map <int, int> group_min;
vector<pair<int, int>> movements = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void dfs(int i, int j, int d, vector<int>& group) {
	if (i < 0 || j < 0 || i >= L || j >= C) return;

	if (visited[i][j] == p) return;
	visited[i][j] = p;

	if (grid[i][j] == -1) return;

	if (grid[i][j] > 0) {
		tower_cost[grid[i][j]] = 1;
		tower_group[grid[i][j]] = p - 1;
		d = D;
		group.pb(grid[i][j]);
	}

	if (d == 0) return;

	for (pii dr : movements) {
		int new_i = i + dr.first;
		int new_j = j + dr.second;
		dfs(new_i, new_j, d-1, group);
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	cin >> L >> C >> D;
	int cnt = 1;

	for (int i = 0; i < L; i++) {
		vector<int> row;
		vector<int> vis_row;
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			vis_row.pb(0);
			if (c == 'T') {row.pb(cnt); cnt++;}
			else if (c == '#') row.pb(-1);
			else row.pb(0);
		}
		grid.pb(row);
		visited.pb(vis_row);
	}

	vector<vector<int>> groups; 
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 0 && grid[i][j] > 0) {
				vector<int> group; group_min[p-1] = 1;
				dfs(i, j, D, group);
				groups.pb(group); p++;
			}
		}
	}

	int cost = groups.size();
	int Q; cin >> Q;
	while (Q--) {
		int t, q; cin >> t >> q;
		int group_index = tower_group[t]; tower_cost[t] = q;

		int mn = INF;
		for (int tower : groups[group_index]) {
			mn = min(mn, tower_cost[tower]);
		}

		cost += mn - group_min[group_index];
		group_min[group_index] = mn;
		cout << cost << "\n";
	}
	return 0;
}