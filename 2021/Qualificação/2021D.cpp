# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

// Não obtem 100 pontos
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// Encontrar todos números diferentes de zero
// Complexidade O(n*m)
void p1() {
	int n, m, s; cin >> n >> m >> s;
	set<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			if (x) st.insert(x);
		}
	}
	cout << st.size() << "\n";
	return;
}

// Complexidade O(q*n*m) 
void p2() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> predios[q]; 
	
	for (int i = 0; i < q; i++) {
		int x0, x1, h; cin >> x0 >> x1 >> h;
		predios[i].pb(--x0); predios[i].pb(--x1); predios[i].pb(h);
	}

	int foto[n][m]; memset(foto, 0, sizeof(foto));
	vi alturas(m, 0);

	for (int p = 0; p < q; p++) {
		int x0 = predios[p][0], x1 = predios[p][1], h = predios[p][2];
		for (int j = x0; j <= x1; j++) { // Iterar lateralmente
			if (h > alturas[j]) {
				for (int i = alturas[j]; i < h; i++) foto[i][j] = p+1;
				alturas[j] = h;
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			cout << foto[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

struct predio {
	int x_min, x_max, h, index;
};

bool cmp(const vector<int>& adj1, const vector<int>& adj2) {
	return (adj1.size() > adj2.size());
}

bool dfs(vector<set<int>>& adj, vector<int>& color, int i) {
	color[i] = 1;
	for (int v : adj[i]) {
		if (color[v] == 1) return true;
		if (color[v] == 0 && dfs(adj, color, v)) return true;
	}
	color[i] = 2; // Mark as processed
	return false;
}

bool hasCycle(vector<set<int>>& adj) {
	int n = adj.size();
	vector<int> color(n, 0); // 0 -> Unvisited, 1 -> Visiting, 2 -> Visited
	for (int i = 0; i < n; i++) {
		if (color[i] == 0)
			if (dfs(adj, color, i)) 
				return true;
	}
	return false;
}
/*
*/

void p3() {
	// Calcular retângulo mínimo de cada prédio

	int n, m, s; cin >> n >> m >> s;
	map<int, int> x_min; x_min[0] = 1;
	map<int, int> x_max; x_max[0] = m;
	map<int, int> h_max; h_max[0] = n;
	
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x; grid[i][j] = x;
			if (!x_min[x]) x_min[x] = INF;

			x_min[x] = min(x_min[x], j+1);
			x_max[x] = max(x_max[x], j+1);
			h_max[x] = max(h_max[x], n-i);  
		}
	}

	vector<predio> predios;
	for (pii p : x_min) {
		int idx = p.first;
		predio pr; 
		pr.x_min = x_min[idx]-1;
		pr.x_max = x_max[idx]-1;
		pr.h = h_max[idx];
		pr.index = idx;
		predios.pb(pr);
	}

	vector<set<int>> adj(s+1);
	for (predio p : predios) {
		int id = p.index;
		for (int j = p.x_min; j <= p.x_max; j++) {
			for (int i = n-p.h; i < n; i++ ) {
				if (grid[i][j] != id) {
					adj[id].insert(grid[i][j]); // Add edge do mais atrás para o mais à frente
				}
			}
		}
	}

	if (hasCycle(adj)) {
		cout << "-1\n"; return;
	}

	set<pair<int, int>> size_index;
	for (int i = 0; i <= s; i++) {
		size_index.insert({(int)adj[i].size(), i});
	}

	map<int, predio> index_predio;
	for (predio p : predios) {
		index_predio[p.index] = p;
	}

	for (pii p : size_index) {
		int index = p.second;
		if (index == 0) continue;
		if (index_predio.find(index) != index_predio.end()) {
			predio pr = index_predio[index];
			cout << pr.x_min+1 << " " << pr.x_max + 1 << " " << pr.h << " " << index << "\n";
		}
	}
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else if (p == 2) p2();
    else p3();
    return 0;
}