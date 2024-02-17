#include <bits/stdc++.h>

using namespace std;

ifstream fin ("matprod.in");
ofstream fout ("matprod.out");

int m[1005][1005], a[1005][1005];

int spe(int i, int j, int n)
{
    int s = 0;
    while(j >= 1)
    {
        s += m[i][j];
        j--;
    }
    j++;
    while(i >= 1)
    {
        s += m[i][j];
        i--;
    }
    return s;
}

int main()
{
    int n, i, j, ss = 0, sc = 0, rc = 0, r = 0, x;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            fin >> x;
            if(j == 1)
            {
                rc += sc*x;
                sc += x;
            }
            r = ss*x + r;
            fout << r << ' ';
            ss += x;
        }
        ss = sc;
        r = rc;
        fout << '\n';
    }
    return 0;
}
