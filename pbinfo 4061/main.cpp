#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lantq.in");
ofstream fout ("lantq.out");

map <int, set<int>> adj;
vector <int> sol;
int vf[25], fn;

void dfs(int st) {
    vf[st] = 1;
    if(st == fn) {
        ok = true;
        for(auto x : sol)
            fout << x << ' ';
        fout << '\n';
        vf[st] = 0;
        return;
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
    fin >> fn;
    if(!adj[fn].empty()) {
        for(int i = 1; i <= n; i++) {
            if(i != fn) {
                sol.push_back(i);
                dfs(i);
                sol.pop_back();
            }
        }
    }
    else
        fout << "NU EXISTA";
    return 0;
}
