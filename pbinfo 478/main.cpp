#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ciclu.in");
ofstream fout ("ciclu.out");

map <int, set<int>> adj;
vector <int> v;
bool vf[21];

void dfs(int st, int p) {
    vf[st] = 1;
    v.push_back(st);
    for(auto x : adj[st]) {
        if(x == p && v.size() != 2) {
            v.push_back(x);
            for(auto x : v)
                fout << x << ' ';
            exit(0);
        }
        if(!vf[x]) {
            dfs(x, p);
            v.pop_back();
        }
    }
}

int main()
{
    int n, m, p, n1, n2;
    fin >> n >> m;
    for(int i = 1; i <= m; i++) {
        fin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }
    fin >> p;
    dfs(p, p);
    return 0;
}
