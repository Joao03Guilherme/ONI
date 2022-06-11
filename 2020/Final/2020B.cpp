# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// Não obtem 100 pontos
int main()
{
    IOS;
    ll k, q; cin >> k >> q;
    bitset<64> bs(k); vector<int> nums;
    for (int i = 0; i < 64; i++) {
    	if (bs[i]) nums.pb(i);
    }

    int mx_len = max(1, nums.back());
    if (mx_len == 1) {
    	if (nums.back() == 0) cout << "1\n1";
    	else cout << "2\n2 1";
    } else {
    	vector<int> ans;
    	int mx = 0;
    	for (int x : nums) {
    		int diff = mx_len - x;
    		mx += 2*x + diff;
    	}	

    	for (int x : nums) {
    		int cnt = 0;
    		int starting = mx - 2 * x - (mx_len - x) + 1;
    		while(cnt < x) {
    			ans.pb(starting+1); ans.pb(starting);
    			starting += 2;
    			cnt++;
    		}

    		while (cnt < mx_len) {
    			ans.pb(starting);
    			starting++; 
    			cnt++;
    		}

    		mx -= 2 * x + (mx_len - x);
    	}
    	cout << ans.size() << "\n";
    	for (int x : ans) cout << x << " ";
    }
    return 0;   
}
