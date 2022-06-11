# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int valores[10000001];
int dp[10000001];

int main(){
	int n; cin>>n;
	memset(dp, 0, sizeof(dp));
	memset(valores, 0, sizeof(valores));

	for(int i=0;i<n;i++){
		int x; cin>>x;
		valores[x]++;
	}

	int ans=0;
	for(int i=10000001;i>0;i--){
		if(valores[i]){
			for(int j=i;j<10000000;j+=i){
				dp[i] = max(dp[i], valores[i]+dp[j]);
			}
			ans = max(ans, dp[i]);
		}
	}
	//
	cout<<ans<<"\n";
	return 0;
}