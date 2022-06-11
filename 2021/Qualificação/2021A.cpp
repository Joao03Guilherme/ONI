# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
# define ll long long int
# define vi vector<int>
# define pii pair<int, int>
using namespace std;

const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int sliding_window(vector<int>& a, int low, int high, int k) {
    if (low == -1 || high == (int)a.size()) return -INF; // Cannot take photo
    int max_len = min(k, high-low+1);

    int sum = 0;
    for (int i = low; i < low + max_len; i++) {
        sum += a[i];
    }

    int ans = sum;
    for (int i = low+1; i+k-1 <= high; i++) { 
        sum += a[i+k-1] - a[i-1];
        ans = max(ans, sum);
    }

    return ans;
}

void p2(int n, int k) {
    vi a(n); for (int& x : a) cin >> x;
    int ans = 0, curr = 0;
    for (int i = 0; i < k; i++) curr += a[i];

    for (int i = 1; i+k-1 < n; i++) {
        curr += a[i+k-1] - a[i-1];
        ans = max(ans, curr + sliding_window(a, 0, i-1, k) + sliding_window(a, i+k+1, n-1, k));
    }

    cout << ans << "\n";
}

void p1(int n, int k) {
    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 0; i < n-1; i++) cout << a[i] + k*b[i] << " ";
    cout << a[n-1] + k*b[n-1] << "\n";
}

int main()
{
    IOS;
    int p; cin >> p;
    int n, k; cin >> n >> k;
    if (p == 1) p1(n ,k);
    else p2(n, k);
    return 0;
}