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
vector<pair<int, int>> movements = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void bfs(int i, int j, int d, vector<int>& group) {
	queue<pair<pii, int>> q; q.push({{i,j}, d});
	while (!q.empty()) {
		pair<pii, int> curr = q.front(); q.pop();
		int i = curr.first.first, j = curr.first.second, d = curr.second;

		if (visited[i][j] > d) continue;
		visited[i][j] = d;

		if (grid[i][j] == -1) continue;

		if (grid[i][j] > 0) {
			visited[i][j] = D;
			tower_cost[grid[i][j]] = 1;
			tower_group[grid[i][j]] = p - 1;
			d = D;
			group.pb(grid[i][j]);
		}

		if (d <= 0) continue;

		for (pii dr : movements) {
			int new_i = i + dr.first;
			int new_j = j + dr.second;
			if (new_i < 0 || new_j < 0 || new_i >= L || new_j >= C) continue;
			q.push({{new_i, new_j}, d-1});
		}
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

	visited = vector<vector<int>> (L, vector<int>(C, -1));
	for (int i = 0; i < L; i++) {
		vector<int> row;
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			if (c == 'T') {row.pb(cnt); cnt++;}
			else if (c == '#') row.pb(-1);
			else row.pb(0);
		}
		grid.pb(row);
	}

	vector<vector<int>> groups; 
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] > 0) continue;
			if (grid[i][j] <= 0) continue;
			
			vector<int> group;
			bfs(i, j, D, group);
			groups.pb(group); p++;	
		}
	}

	vector<multiset<int>> groups_cost;
	for (vector<int> group : groups) {
		multiset<int> g_cost;
		for (int i = 0; i < group.size(); i++) g_cost.insert(1);
			groups_cost.pb(g_cost);
	}

	int cost = groups.size();
	int Q; cin >> Q;
	while (Q--) {
		int t, q; cin >> t >> q;

		int prev_tower_cost = tower_cost[t];
		int group_index = tower_group[t];
		int new_tower_cost = tower_cost[t] = q;
 
		int prev_min_cost = *(groups_cost[group_index].begin());
		auto itr = groups_cost[group_index].find(prev_tower_cost);
		groups_cost[group_index].erase(itr);
		groups_cost[group_index].insert(new_tower_cost);
		int new_min_cost = *(groups_cost[group_index].begin());
 
		cost += (ll)new_min_cost - (ll)prev_min_cost;
		cout << cost << "\n";
	}
	return 0;
}