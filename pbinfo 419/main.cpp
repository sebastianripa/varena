#include <bits/stdc++.h>

using namespace std;

ifstream fin ("subgraf1.in");
ofstream fout ("subgraf1.out");

map <int, set<int>> adj;
int vf[101];
bool m[101][101];

int main()
{
    int n, n1, n2, mini = 100, og1, og2;
    fin >> n;
    while(!fin.eof()) {
        fin >> n1 >> n2;
        if(og1 != n1 || og2 != n2) {
            if(n2 < n1)
                swap(n1, n2);
            adj[n1].insert(n2);
            if(!m[n1][n2]) {
                vf[n1]++;
                vf[n2]++;
                m[n1][n2] = 1;
            }
        }
        og1 = n1;
        og2 = n2;
    }
    for(int i = 1; i <= n; i++) {
        mini = min(mini, vf[i]);
    }
    int ans = 0;
    for(auto x : adj) {
        if(vf[x.first]!= mini) {
            for(auto y : x.second) {
                if(vf[y] != mini)
                    ans++;
            }
        }
    }
    fout << ans;
    return 0;
}
