# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

// Não obtem 100 pontos
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int n, k;
vector<int> s;

void p1() {
    ll ans = INFLL, curr = 0ll;
    for (int i = 0; i < k; i++) {
        curr += (ll) s[i];
    }

    ans = min(ans, curr);
    for (int i = 1; i+k-1 < n; i++) {
        curr += (ll) s[i+k-1] - (ll) s[i-1];
        ans = min(ans, curr);
    }

    cout << ans << "\n";
}

// Vide: https://www.geeksforgeeks.org/number-subarrays-sum-less-k/
ll segments_less_than_T(ll T) {
    int i = 0, j = 0;
    ll ans = 0; ll sum = s[0];
    while (i < n && j < n) {
        if (sum <= T) {
            j++;
            if (i <= j) ans += j - i;
            if (j < n) sum += s[j]; // Cuidado com o último elemento
        }
        else {
            sum -= s[i];
            i++;
        }
    }
    return ans; 
}

// Binary search for the answer
void p2() {
    ll r = 0ll;
    for (int i = 0; i < n; i++) r += (ll) s[i];

    ll l = 0ll;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (segments_less_than_T(mid) < k) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";
    return;
}

ll merge(vector<ll>& p, vector<ll>& tmp, int low, int mid, int high) {
    int k = low, i = low, j = mid + 1;
    ll inversion_count = 0ll; 

    while (i <= mid && j <= high) {
        if (p[i] <= p[j]) {
            tmp[k++] = p[i++];
        }
        else {
            tmp[k++] = p[j++];
            inversion_count += (mid - i + 1); // Número de elementos restantes na primeira metade
        }
    }

    while (i <= mid) tmp[k++] = p[i++];
    while (j <= high) tmp[k++] = p[j++];

    for (int i = low; i <= high; i++) p[i] = tmp[i];
    return inversion_count;
}

ll mergeSort(vector<ll>& p, vector<ll>& tmp, int low, int high) {
    if (low >= high) return 0ll;
    int mid = (low + high) / 2;
    ll inversion_count = 0ll;

    inversion_count += mergeSort(p, tmp, low, mid);
    inversion_count += mergeSort(p, tmp, mid+1, high);
    inversion_count += merge(p, tmp, low, mid, high);

    return inversion_count;
}

ll segments_average_less_than_T(ll T) {
    vector<ll> p(n+1); p[0] = 0;
    vector<ll> tmp(n+1);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + (s[i-1] - T-1); // Cuidado!!! Subtrair um ao T, por causa de floor(média)
    ll inv = mergeSort(p, tmp, 0, n);
    return inv;
}

void p3() {
    ll r = 0ll;
    for (int i = 0; i < n; i++) r += (ll) s[i];
    ll l = 0ll;
    
    while (l < r) {
        ll mid = (l + r) / 2;
        if (segments_average_less_than_T(mid) < k) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";
    return;
}
int main() 
{
    IOS;
    int p; cin >> p;
    cin >> n >> k;
    s.resize(n);
    for (int& x : s) cin >> x;

    if (p == 1) p1();
    else if (p == 2) p2();
    else p3();
    return 0;
}