# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

struct atividade {
    int start, finish;
};

bool cmp(const atividade& a, const atividade& b) {
    return a.finish < b.finish;
}

void p1() {
    int n; cin >> n;
    vector<atividade> atividades;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        atividades.pb(atividade{a, b});
    }
    sort(atividades.begin(), atividades.end(), cmp); // Greedy
    int cnt = 0;
    int mx_time = -1;
    for (atividade a : atividades) {
        if (a.start >= mx_time) {
            mx_time = a.finish;
            cnt++;
        }
    }
    cout << cnt << "\n";
}

bool cmp2(const atividade& a, const atividade& b) {
	if (a.start == b.start) {
		return a.finish > b.finish;
	}
	return a.start < b.start;
}

// Incompleto, é preciso utilizar sweep line
void p2() {
	int n; cin >> n;
	vector<atividade> atividades;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		atividades.pb(atividade{a, b});
	}
	sort(atividades.begin(), atividades.end(), cmp2); // Interval covering

	atividade a1 = {-1, -1};
	atividade a2 = {-1, -1};

	int min1 = -1, mx1 = -1;
	int min2 = -1, mx2 = -1;

	for (atividade a : atividades) {
		if (a.start >= a1.finish) {
			a1 = a;
			if (a.start < a2.finish) mx1 = a1.finish; // Se estiver a ser coberto
		} else if (a.start >= a2.finish) {
			a2 = a;
			if (min1 == -1) min1 = a1.start;
			if (min2 == -1) min2 = a2.start;
			mx1 = max(mx1, a1.finish);
			mx2 = max(mx2, a2.finish);
		} else {
			cout << "-1\n"; return;
		}
	}
	cout << min(mx1 - min1, mx2 - min2) << "\n"; 
	return;
}

int main()
{
    IOS;
    int p; cin >> p;
    if (p == 1) p1();
    else p2();
    return 0;
}