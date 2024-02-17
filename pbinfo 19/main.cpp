#include <bits/stdc++.h>

using namespace std;

ifstream fin ("BFS.in");
ofstream fout ("BFS.out");

map <int, set<int>> adj;
queue <int> q;
int vf[105];

void bfs(int st) {
    if(!q.empty())
        q.pop();
    vf[st] = 1;
    for(auto x : adj[st]) {
        if(!vf[x]) {
            q.push(x);
            vf[x] = 1;
            fout << x << ' ';
        }
    }
    if(q.empty())
        return;
    bfs(q.front());
}

int main()
{
    int n, m, st;
    fin >> n >> m >> st;
    for(int i = 1; i <= m; i++) {
        int n1, n2;
        fin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }
    fout << st << ' ';
    bfs(st);
    for(int i = 1; i <= n; i++) {
        if(!vf[i]) {
            fout << i << ' ';
            bfs(i);
        }
    }
    return 0;
}
