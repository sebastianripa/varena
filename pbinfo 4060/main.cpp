#include <bits/stdc++.h>

using namespace std;

ifstream fin ("gradk.in");
ofstream fout ("gradk.out");

map <int, set<int>> adj;
vector <int> v;
int vf[101];
bool m[101][101];

int main()
{
    int n, n1, n2, og1, og2, k;
    fin >> n >> k;
    while(!fin.eof()) {
        fin >> n1 >> n2;
        if(og1 != n1 || og2 != n2) {
            if(n1 > n2)
                swap(n1, n2);
            adj[n1].insert(n2);
            adj[n2].insert(n1);
            if(!m[n1][n2]) {
                vf[n1]++;
                vf[n2]++;
                m[n1][n2] = 1;
            }
        }
    }
    int ans = 0;
    for(auto x : adj) {
        if(vf[x.first] == k) {
            ans++;
            v.push_back(x.first);
        }
    }
    if(!ans)
        fout << "NU EXISTA";
    else {
        fout << ans << ' ';
        for(auto x : v)
            fout << x << ' ';
    }
    return 0;
}
