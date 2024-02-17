#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cruce.in");
ofstream fout ("cruce.out");

int m[505][505], sm[505][505], smi[505][505];

int main()
{
    int n, k, i, j, cnt, vc, vmc = 1, l, c;
    fin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            fin >> m[i][j];
            sm[i][j] += sm[i][j-1] + sm[i-1][j] - sm[i-1][j-1] + m[i][j];
        }
    }
    for(i = n, cnt = 1; i >= 1; i--, cnt++)
    {
        for(j = n; j >= 1; j--)
            smi[cnt][j] = smi[cnt][j+1] + smi[cnt-1][j] - smi[cnt-1][j+1] + m[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            vc = sm[n][n];
            vc = vc - (sm[n][j-1] - sm[i+k-1][j-1] + sm[i-1][j-1]);
            vc = vc - (smi[n][j+k] - smi[i+k-1][j+k] + smi[i-1][j+k]);
            if(vc > vmc)
            {
                vmc = vc;
                l = i;
                c = j;
            }
        }
    }
    fout << vmc << ' ' << l << ' ' << c;
    return 0;
}
