#include <bits/stdc++.h>

using namespace std;

ifstream fin ("genius.in");
ofstream fout ("genius.out");

int lvl1 = 1, lvl2 = 0;
bool vf[50005], vf1[50005];
long long ans = 0;
queue <int> nxt;
map <int, set<int>> adj;

void bfs(int st) {
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
    int n, m, nrn = 0;
    fin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int n1, n2;
        fin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
        if(!vf1[n1]) {
            vf1[n1] = 1;
            nrn++;
        }
        if(!vf1[n2]) {
            vf1[n2] = 1;
            nrn++;
        }
    }
    int x;
    int p;
    fin >> x >> p;
    if(nrn != n) {
        fout << -1;
        exit(0);
    }
    bfs(x);
    fout << p+ans;
    return 0;
}
