# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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

// Complexidade O(q*n*m) // Acho que n passa no limite de tempo
// Vide sweepline e coordinate compression?
void p2() {
	int n, m, q; cin >> n >> m >> q;
	vi predios[q];
	
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

/*
void print_adj(vi predios[], vector<bool>& vis, set<int> adj[], int s, int u) {
	if (vis[u]) return;
	if (adj[u].size() == 0) {
		cout << predios[u][0] << " " << predios[u][1] << predios[u][2] << u << "\n";
		return;
	}
	for (int neighbour : adj[u]) {
		if (vis[neighbour]) continue;
		vis[neighbour] = true;
		print_adj(predios, vis, adj, s, neighbour);
		cout << predios[u][0] << " " << predios[u][1] << predios[u][2] << u << "\n";
	}
	return;
}
*/

void p3() {
	int n, m, s; cin >> n >> m >> s;
	int grid[n][m]; memset(grid, 0, sizeof(grid));
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) cin >> grid[i][j];
	} 

	vector<vi> predios(s+1);
	for (int i = 0; i <= s; i++) predios[i] = {INF, -INF, 0}; // x0, x1, h

	vector<set <int>> adj(s+1);
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			for (int y1 = 0; y1 < y; y1++) {
				vi atual = predios[ grid[y][x] ];
				vi frente = predios[ grid[y1][x] ];
				predios[ grid[y1][x] ] = {min(frente[0],x), max(frente[1], x), max(frente[2], y1+1)};
				predios[ grid[y][x]  ] = {min(atual[0],x), max(atual[1], x), max(atual[2], y+1)};
				if (grid[y1][x] != grid[y][x]) {
					adj[ grid[y][x] ].insert( grid[y1][x] ); // O y1 está à frente
				}
			}
		}
	}

	debug(predios, adj);
	// Não pode haver edges bidirecionais no grafo (ciclos, no fundo)
	// Um prédio não pode estar atrás e à frente ao mesmo tempo
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else if (p == 2) p2();
    else p3();
    return 0;
}

/*
	COISAS A TOMAR ATENÇÃO
    - Overflow
    - Prestar atenção aos limites do problema
    - É preciso apenas determinar um número ou a resposta "toda"
    - Utilizar Sievo para primos
    - Precomputação
    - Inverter o problema
    - Identificar implicações lógicas
    - Problemas com vetores -> O(n)?
    - Manipular fórmulas dadas
    - Há monotonia -> pesquisa binária usa invariance
    - Para números reais, usar setprecision(20)
*/