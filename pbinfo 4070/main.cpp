#include <bits/stdc++.h>

using namespace std;

map <int, vector<int>> adj;

int main()
{
    int n, m, k, n1, n2;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> n1 >> n2;
        if(n1%k && n2%k)
            adj[n1].push_back(n2);
    }
    int ans = 0;
    for(auto x : adj) {
        for(auto y : x.second)
            ans++;
    }
    cout << ans;
    return 0;
}
