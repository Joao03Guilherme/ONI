# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const int MX = 2e5 + 1;
vector<bool> cond(MX, false);

void potencia_base_dois_menos_um() {
    int p = 2;
    while (p+1 <= MX) {
        cond[p-1] = true;
        p = p << 1;
    }
}

void sievo_de_erastotenes() {
    for (int i = 0; i < MX; i++) cond[i] = true;
    for (int i = 2; i*i < MX; i++) {
        if (cond[i]) {
            for (int j = i*i; j < MX; j += i) cond[j] = false;
        }
    }
}

int main() 
{
    IOS;
    int p; cin >> p;
    if (p == 1) potencia_base_dois_menos_um();
    else sievo_de_erastotenes();

    int n; cin >> n;
    int l = 1, r = n;
    while (l < r) {
        if (cond[l+r]) {
            for (int i = l, j = r; i < j; i++, j--) {
                cout << i << " " << j << "\n";
            }
            r = l-1;
            l = 1;
        }
        else l++;
    }
    return 0;
}