#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("bfs.in");
ofstream fout ("bfs.out");

int vf[100001], v[100001], ans, lvl1 = 1, lvl2 = 0;
map <int, vector<int>> adj;
queue <int> nxt;

class graph {
public:
    void addEdge(int x, int y) {
        adj[x].push_back(y);
    }
    void bfs(int st);
};

void graph::bfs(int st) {
    if(!nxt.empty())
        nxt.pop();
    if(lvl1 == 0) {
        lvl1 = lvl2;
        lvl2 = 0;
        ans++;
    }
    vf[st] = 1;
    for(auto x : adj[st]) {
        if(!vf[x]) {
            nxt.push(x);
            v[x] = ans+1;
            lvl2++;
            vf[x] = 1;
        }
    }
    if(nxt.empty())
        return;
    lvl1--;
    bfs(nxt.front());
}

int main()
{
    int n, m, s, x, y;
    graph g;
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.bfs(s);
    for(int i = 1; i <= n; i++) {
        if(i == s)
            cout << "0 ";
        else if(!v[i])
            cout << -1 << ' ';
        else
            cout << v[i] << ' ';
    }
    return 0;
}
