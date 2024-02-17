#include <bits/stdc++.h>

using namespace std;

ifstream fin ("graf_partial_1.in");
ofstream fout ("graf_partial_1.out");

set<int> adj[105];
int m[105][105];

int main()
{
    int n;
    fin >> n;
    int n1, n2;
    while(fin >> n1 >> n2) {
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }
    int mini = 100, maxi = 0;
    for(int i = 1; i <= n; i++) {
        int s = adj[i].size();
        mini = min(mini, s);
        maxi = max(maxi, s);
    }
    int nrm = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == maxi) {
            for(auto x : adj[i]) {
                if(adj[x].size() != mini) {
                    m[i][x] = 1;
                    m[x][i] = 1;
                }
                else
                    ans++;
            }
        }
        else if(adj[i].size() == mini) {
            for(auto x : adj[i]) {
                if(adj[x].size() != maxi) {
                    m[i][x] = 1;
                    m[x][i] = 1;
                }
                else
                    ans++;
            }
        }
    }
    fout << ans/2 << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            fout << m[i][j] << ' ';
        fout << '\n';
    }
    return 0;
}
