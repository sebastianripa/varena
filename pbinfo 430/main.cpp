#include <bits/stdc++.h>

using namespace std;

ifstream fin ("izolate.in");
ofstream fout ("izolate.out");

map <int, vector<int>> adj;
set <int> iz;

int main()
{
    int n, z, y, ans, og1, og2;
    fin >> n;
    while(!fin.eof()) {
        fin >> z >> y;
        if(og1 != z || og2 != y) {
            adj[z].push_back(y);
            adj[y].push_back(z);
        }
        og1 = z;
        og2 = y;
    }
    for(int i = 1; i <= n; i++) {
        if(adj[i].empty()) {
            ans++;
            iz.insert(i);
        }
    }
    fout << ans << ' ';
    for(auto x : iz)
        fout << x << ' ';
    return 0;
}
