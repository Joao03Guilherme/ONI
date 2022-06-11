# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
// using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

typedef pair<long long int,long long int>pii;

int main(){
    int n,q;
    cin>>n>>q;
    pii arr[2*n];
    for(int i=0;i<n;i++){
        long long int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        long long int length=y2-y1;
        arr[2*i]=pii(x1,length);
        arr[2*i+1]=pii(x2,-length);
    }
    sort(arr,arr+2*n);
    pii queries[q];
    for(int i=0;i<q;i++){
        long long int x;
        cin>>x;
        queries[i]=pii(x,i);
    }
    sort(queries,queries+q);
    int pos=0;
    long long int len=0;
    long long int answers[q];
    for(int i=0;i<q;i++){
        while(pos<2*n && arr[pos].first<=queries[i].first){
            len+=arr[pos].second;
            pos++;
        }
        answers[queries[i].second]=len;
    }
    for(int i=0;i<q;i++)cout<<answers[i]<<endl;
        
    return 0;
}