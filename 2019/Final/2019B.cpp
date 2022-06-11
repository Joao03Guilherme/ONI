# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds;

// Não obtem 100 pontos
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> ascending_ordered_set;
typedef tree<ll, null_type,greater<ll>, rb_tree_tag,tree_order_statistics_node_update> descending_ordered_set;

int main()
{
    IOS;
    ascending_ordered_set inf;
    descending_ordered_set sup;

    ll k, n, q; cin >> k >> n >> q;
    for (ll i = 0ll; i < n; i++) {
        ll x; cin >> x;
        if (x > k) sup.insert(x);
        else inf.insert(x);
    }

    while (q--) {
        char c; ll x; cin >> c >> x;
        if (c == '?') {
            if (x < k) {
                ll index = inf.order_of_key(x);
                ll dist = abs(k-x);

                ll x2 = -1;
                ll a = sup.order_of_key(k + dist);
                ll b = 0;
                if (index > 0) {
                    x2 = *(inf.find_by_order(index-1));
                    b = sup.order_of_key(k + abs(k - x2));
                }
                cout << a - b << "\n";
            } else {
                ll index = sup.order_of_key(x);
                ll dist = abs(k - x);

                ll a = inf.order_of_key(k - dist + 1);
                ll b = 0;
                ll x2 = -1;
                if (index - 1 > 0) {
                    x2 = *(sup.find_by_order(index-1));
                    b = inf.order_of_key(k - abs(x2 - k) + 1);
                }
                cout << a - b << "\n";
            }
        } else if (c == '+') {
            if (x < k) inf.insert(x);
            else sup.insert(x);
        } else {
            if (x < k) inf.erase(x);
            else sup.erase(x);
        }

    }
    return 0;
}