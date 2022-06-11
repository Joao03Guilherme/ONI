# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main(){
    int n, I;
    ll a,b;
    cin >> n >> a >> b >> I;
    I--;

    vector<ll> prize(n, 0), Zprize(n, 0);
    vector<int> zona(n, 0);
    for(int i = 0; i < n; i++) cin >> prize[i];
    for(int i = 0; i < n; i++){
        cin>>zona[i];
        zona[i]--;
    }

    int z = zona[n-1] + 1;
    for(int i = 0; i < n; i++){
        if(i == I) Zprize[zona[i]] += prize[i];
        else Zprize[zona[i]] += max(prize[i]-b-a, 0ll);
    }

    int zonai = zona[I];
    ll A1=0, A2=0, B1=0, B2=0, cumm=0;
    for(int i = zonai + 1; i < z; i++){
        cumm -= 2*b; // Mudar de zona
        cumm += Zprize[i];
        A1 = max(A1, cumm);
    }

    cumm=0;
    for(int i = zonai-1; i >= 0; i--){
        cumm -= 2*b;
        cumm += Zprize[i];
        A2 = max(A2,cumm);
    }

    cumm=0;
    for(int i=zonai+1;i<z;i++){
        cumm-=b;
        cumm+=Zprize[i];
        B1=max(B1,cumm);
    }

    cumm=0;
    for(int i=zonai-1;i>-1;i--){
        cumm-=b;
        cumm+=Zprize[i];
        B2=max(B2,cumm);
    }

    ll ans=max(A1+B2, B1+A2);
    ans += Zprize[zonai];
    cout << ans << "\n";
}