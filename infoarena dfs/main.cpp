#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dfs.in");
ofstream fout ("dfs.out");

bool vf[100001];
map <int, vector<int>> adj;

class graph {
public:
    void addEdge (int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void dfs(int st);
};

void graph::dfs(int st) {
    vf[st] = 1;
    for(auto x : adj[st]) {
        if(!vf[x])
            dfs(x);
    }
}

int main()
{
    int n, m, x, y, ans = 0;
    graph g;
    fin >> n >> m;
    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        g.addEdge(x, y);
    }
    for(int i = 1; i <= n; i++)
    {
        if(vf[i] == 0) {
            g.dfs(i);
            ans++;
        }
    }
    fout << ans;
    return 0;
}
