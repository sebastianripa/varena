#include <bits/stdc++.h>

using namespace std;

ifstream in ("triunghiuri.in");
ofstream out ("triunghiuri.out");

unsigned int m[1005][1005], ms[1005][1005];

int main()
{
    int n, q, lin, col, k, i, j, st = 0, stm = 0;
    in >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            in >> m[i][j];
            ms[i][j] = ms[i][j-1] + m[i][j];
        }
    }
    fin >> q;
    for(j = 1; j <= q; j++)
    {
        st = 0;
        in >> col;
        in >> k;
        in >> lin;
        if(k < 0)
        {
            k = k - k*2;
            for(i = 1; i <= k; i++)
                st += ms[lin-k+i][col] - ms[lin-k+i][col-i];
            stm = max(st, stm);
        }
        else
        {
            for(i = 1; i <= k; i++)
                st += ms[lin+i-1][col+k-i] - ms[lin+i-1][col-1];
            stm = max(st, stm);
        }
    }
    out << stm;
    return 0;
}
