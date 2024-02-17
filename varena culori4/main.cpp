#include <bits/stdc++.h>

using namespace std;

ifstream fin ("culori4.in");
ofstream fout ("culori4.out");

int v[10005], a[10005][505];
char m[10005][505];

int main()
{
    fin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int c, n, ogx, x, l, lm = 0, nrs = 0, i, j = 1, k = 1, nrp = 0, cm = 0;
    bool dif = true;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            dif = true;
            fin >> l >> x;
            for(j = 2; j <= l; j++)
            {
                ogx = x;
                fin >> x;
                if(x == ogx)
                    dif = false;
            }
            if(dif == true)
            {
                if(lm < l)
                {
                    lm = l;
                    nrs = 1;
                }
                else if(lm == l)
                    nrs++;
            }
        }
        fout << lm << ' ' << nrs;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> v[i];
            if(lm < v[i])
            {
                lm = v[i];
                nrp = 0;
            }
            else if(lm == v[i])
                nrp++;
            for(j = 1; j <= v[i]; j++)
                fin >> a[i][j];
        }
        for(i = 1; i <= n; i++)
            v[i] = 0;
        for(i = 1; i <= n; i++)
        {
            if(l == lm)
            {
                for(j = 1; j <= lm; j++)
                    m[k][j] = a[i][j];
                k++;
            }
        }
        for(i = 1; i <= lm; i++)
        {
            for(j = 1; j <= nrp; j++)
            {
                if(m[i][j] > v[i])
                    v[i] = m[i][j];
            }
        }
        for(i = 1; i <= lm; i++)
        {
            for(j = 1; j <= nrp; j++)
            {
                if(m[i][j] != v[i] && m[i][j] != 0)
                {
                    for(k = 1; k <= lm; k++)
                        m[j][k] = 0;
                }
            }
        }
        for(i = 1; i <= nrp; i++)
        {
            if(m[i][1] != 0)
            {
                for(j = 1; j <= lm; j++)
                    fout << m[i][j];
            }
        }
    }
    return 0;
}
