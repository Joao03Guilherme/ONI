# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

/*
	Gerar retas e ver se existem os outros dois pontos necessários
	Dar "hash" do ponto, multiplicando a coordenada y por 100 000 e somando a coordenada x
*/
struct point {
	int x, y;
};

int distSq(point a, point b) {
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

const int MX = 2'000'020'000;
bitset<MX> bs; // Bitset ocupa menos memória
vector <point> points(0);

int main() 
{
	IOS;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		point p; cin >> p.x >> p.y; points.pb(p);
		bs[p.y * 100000 + p.x] = 1;
	}

	int cnt = 0, area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			point p1 = points[i], p2 = points[j];
			int x = p2.x - p1.x, y = p1.y - p2.y;

			point p3; p3.y = x + p2.y; p3.x = y + p2.x; // Vídeo com ajuda: https://www.youtube.com/watch?v=Z0jWwzxhFSI
			point p4; p4.y = x + p1.y; p4.x = y + p1.x;
		
			if (p3.y * 100000 + p3.x >= 0 && p4.y * 100000 + p4.x >= 0) {
				if (bs[p3.y * 100000 + p3.x] && bs[p4.y * 100000 + p4.x]) {
					cnt++; area = max(area, distSq(p1, p2));
				}
			}

			p3.y = -x + p2.y; p3.x = -y + p2.x;
			p4.y = -x + p1.y; p4.x = -y + p1.x;
		
			if (p3.y * 100000 + p3.x >= 0 && p4.y * 100000 + p4.x >= 0) {
				if (bs[p3.y * 100000 + p3.x] == 1 && bs[p4.y * 100000 + p4.x] == 1) {
					cnt++; area = max(area, distSq(p1, p2));
				}
			}
		}
	}

	cout << cnt / 4 << "\n"; // Cuidado com duplicados
	if (cnt) cout << area << "\n";
}