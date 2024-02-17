#include <bits/stdc++.h>

using namespace std;

ifstream fin ("veriflant.in");
ofstream fout ("veriflant.out");

map <int, set<int>> adj;
int vf[105];

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
    int nrl;
    fin >> nrl;
    while(nrl--) {
        for(int i = 1; i <= n; i++)
            vf[i] = 0;
        bool ok = false, ok1 = true;
        int l, ogx;
        fin >> l >> ogx;
        vf[ogx]++;
        for(int i = 2; i <= l; i++) {
            int x;
            fin >> x;
            if(adj[ogx].find(x) != adj[ogx].end()) {
                vf[x]++;
                if(vf[x] >= 2)
                    ok = true;
            }
            else
                ok1 = false;
            ogx = x;
        }
        if(!ok1)
            fout << "NU" << '\n';
        else {
            if(ok)
                fout << "NEELEMENTAR" << '\n';
            else
                fout << "ELEMENTAR" << '\n';
        }
    }
    return 0;
}
