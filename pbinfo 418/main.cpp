#include <bits/stdc++.h>

using namespace std;

ifstream fin ("subgraf.in");
ofstream fout ("subgraf.out");

map <int, set<int>> adj;

bool prim(int n) {
    if(n < 2)
        return false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, n1, n2, og1 = 0, og2 = 0;
    fin >> n;
    while(!fin.eof()) {
        fin >> n1 >> n2;
        if(og1 != n1 || og2 != n2) {
            if(n1 > n2)
                swap(n1, n2);
            if(!prim(n1) && !prim(n2))
                adj[n1].insert(n2);
        }
        og1 = n1;
        og2 = n2;
    }
    int ans = 0;
    for(auto x : adj) {
        for(auto y : x.second)
            ans++;
    }
    fout << ans;
    return 0;
}
