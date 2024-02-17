#include <bits/stdc++.h>

using namespace std;

ifstream fin ("prajituri.in");
ofstream fout ("prajituri.out");

int v1[10001], v2[10001], f1[101], f2[101];

int main()
{
    int n, m, nrs = 0, nrd = 0, i, j, is, ss, isf, ssf, cont = 0, mini = INT_MAX;
    bool ok = false, g = false;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        fin >> v1[i];
        f1[v1[i]]++;
    }
    for(i = 1; i <= m; i++)
    {
        fin >> v2[i];
        f2[v2[i]]++;
    }
    for(i = 1; i <= n; i++)
    {
        if((v1[i] == v2[1] || ok == true))
        {
            if(ok == true)
            {
                if(v1[i] != v2[j])
                {
                    j = 1;
                    i--;
                    ok = false;
                }
                else
                    j++;
                if(j == m+1)
                {
                    ss = i;
                    if(g == false)
                    {
                        isf = is;
                        ssf = ss;
                        g = true;
                    }
                    cont++;
                }
            }
            else
            {
                ok = true;
                j = 2;
                is = i;
            }
        }

    }
    for(i = 1; i <= m; i++)
        mini = min(f1[v2[i]], mini);
    nrs = isf - 1;
    nrd = n - ssf;
    fout << nrs << ' ' << nrd << '\n' << cont << '\n' << mini;
    return 0;
}
