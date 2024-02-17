#include <bits/stdc++.h>

using namespace std;

ifstream fin ("balon.in");
ofstream fout ("balon.out");

long long a[1001][1001];

int main()
{
    long long cer, n, m, k, p, i, j, x, y, d, s = 0, mx = 0, nrm = 0;
    fin >> cer >> n >> m >> k >> p;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            fin >> a[i][j];
    }
    while(p--)
    {
        fin >> x >> y >> d;
        if(cer != 1)
        {
            if(n-x+1 >= d && m-y+1 >= d)
            {
                for(i = x; i <= x+d-1; i++)
                {
                    for(j = y; j <= y+d-1; j++)
                    {
                        a[i][j]++;
                        if(a[i][j] == k+1)
                        {
                            a[i][j] = 1;
                            s++;
                        }
                    }
                }
            }
            else if(n-x+1 >= d)
            {
                for(i = x; i <= x+d-1; i++)
                {
                    for(j = y; j <= m; j++)
                    {
                        a[i][j]++;
                        if(a[i][j] == k+1)
                        {
                            a[i][j] = 1;
                            s++;
                        }
                    }
                }
            }
            else if(m-y+1 >= d)
            {
                for(i = x; i <= n; i++)
                {
                    for(j = y; j <= y+d-1; j++)
                    {
                        a[i][j]++;
                        if(a[i][j] == k+1)
                        {
                            a[i][j] = 1;
                            s++;
                        }
                    }
                }
            }
            else
            {
                for(i = x; i <= n; i++)
                {
                    for(j = y; j <= m; j++)
                    {
                        a[i][j]++;
                        if(a[i][j] == k+1)
                        {
                            a[i][j] = 1;
                            s++;
                        }
                    }
                }
            }
        }
        else
        {
            if(n-x+1 >= d && m-y+1 >= d)
                s += d*d;
            else if(n-x+1 >= d)
                s = s + d*(m-y+1);
            else if(m-y+1 >= d)
                s = s + d*(n-x+1);
            else
                s = s + (n-x+1)*(m-y+1);
        }
    }
    if(cer == 1)
        fout << s;
    else if(cer == 2)
        fout << s;
    else
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(mx < a[i][j])
                {
                    mx = a[i][j];
                    nrm = 1;
                }
                else if(mx == a[i][j])
                    nrm++;
            }
        }
        fout << mx << ' ' << nrm;
    }
    return 0;
}
