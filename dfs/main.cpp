#include <bits/stdc++.h>
#define first f
#define second s

using namespace std;

map <int, set<int>> adj;
map <int, bool> vis;

class graph {
public:
    void addEdge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void dfs(int st) {
        vis[st] = 1;
        for(auto x : adj[st]) {
            if(!vis[x])
                dfs(x);
        }
    }
};

int main()
{
    int n, x, y, maxi = 0;
    graph g;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        g.addEdge(x, y);
        maxi = max(maxi, x);
    }
    g.dfs(maxi);
    return 0;
}
