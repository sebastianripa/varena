#include <bits/stdc++.h>

using namespace std;

ifstream fin ("faraon.in");
ofstream fout ("faraon.out");

int vf[100005];

struct duo
{
    int vf[100005];
    int j[100005];
};

duo vm[100005];

int main()
{
    int n, m, i, j, x, cnt;
    bool ok = false;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        vf[x]++;
        vm[x].vf[x] = i;
    }
    for(i = 1; i <= m; i++)
    {
        fin >> x;
        for(j = 1; j <= vf[x]; j++)
            fout << vm[x].j << ' ';
        fout << '\n';
    }
    return 0;
}
