#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x; st.insert(x);
    }

    cout << n - st.size() << "\n";
    return 0;
}

