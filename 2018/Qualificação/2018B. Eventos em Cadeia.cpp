# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int N; string s;
	cin >> N >> s;

	ll res = 0, ans = 0, A = 0, T = 0;
	for (int i = 0; i < N; i++) { // Initial pass
		if (s[i] == 'T') res+=A;
		else A++;
	}

	for (int i = N-1; i >= 0; i--) {
		ans = max(ans, res);
		if (s[i] == 'A') A--;
		else {
			T++;
			if (s[i] == '?') {
				res += A-T;
				A--;
			}
		}
	}

	cout << ans << "\n";
 	return 0;
}

