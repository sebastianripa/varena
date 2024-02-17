#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bipartit.in");
ofstream fout ("bipartit.out");

bool v[105];
map <int, set<int>> adj;

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
    int ma;
    fin >> ma;
    for(int i = 1; i <= ma; i++) {
        int x;
        fin >> x;
        v[x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(auto x : adj[i]) {
            if(v[x] == v[i]) {
                fout << "NU";
                exit(0);
            }
        }
    }
    fout << "DA";
    return 0;
}
