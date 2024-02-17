#include <bits/stdc++.h>

using namespace std;

ifstream fin ("graf_partial.in");
ofstream fout ("graf_partial.out");

map <int, set<int>> adj;
int m[105][105];

int main()
{
    int n;
    fin >> n;
    int n1, n2;
    float nrm = 0;
    while(fin >> n1 >> n2) {
        adj[n1].insert(n2);
        adj[n2].insert(n1);
        if(n1 < n2)
            swap(n1, n2);
        if(!m[n1][n2]) {
            m[n1][n2] = 1;
            nrm++;
        }
    }
    float d = 0.5;
    for(int i = 1; i <= n; i++) {
        for(auto x : adj[i]) {
            if(i%2 == x%2)
                nrm = nrm - d;
        }
    }
    fout << nrm;
    return 0;
}
