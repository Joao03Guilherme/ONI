# include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>

using namespace std;
using namespace __gnu_pbds;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

// Use the pair <int, int> trick to store multiple values
typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main() 
{
	IOS;
	int n; cin >> n;
	ordered_multiset st;
	
	int p = 0;
	for (int i = 0; i < n; i++) {
		string s; int v; 
		cin >> s >> v;

		if (s == "INS") st.insert({v, p++}); 
		else if (s == "REM") { 
			st.erase(st.upper_bound({v, INF}));
		}
		else {
			auto itr = st.find_by_order(v-1);
			cout << itr->first << "\n";
		}
	}
	//
	return 0;
}