#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ciclul.in");
ofstream fout ("ciclul.out");

map <int, set<int>> adj;
int vf[25], l, fn;
vector <int> sol;

void dfs(int st) {
    if(sol.size() > 1)
        vf[st] = 1;
    if(st == fn && sol.size() > 1) {
        if(sol.size() == 3) {
            vf[st] = 0;
            return;
        }
        if(sol.size() - 1 != l) {
            vf[st] = 0;
            return;
        }
        else {
            for(auto x : sol)
                fout << x << ' ';
            exit(0);
        }
    }
    for(auto x : adj[st]) {
        if(!vf[x]) {
            sol.push_back(x);
            dfs(x);
            sol.pop_back();
        }
    }
    vf[st] = 0;
}

int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int n1, n2;
        fin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }
    fin >> l;
    for(int i = 1; i <= n; i++) {
        for(int i = 1; i <= n; i++)
            vf[i] = 0;
        sol.push_back(i);
        fn = i;
        dfs(i);
        sol.pop_back();
    }
    return 0;
}
