#include <bits/stdc++.h>

using namespace std;

ifstream fin ("numarspecial.in");
ofstream fout ("numarspecial.out");

int v[1000005];
bool c[1000005];

void ciur()
{
    int i, j;
    c[1] = 1;
    c[0] = 1;
    for(i = 2; i <= 1000000; i++)
    {
        if(c[i] == 0)
        {
            for(j = i*2; j <= 1000000; j += i)
                c[j] = 1;
        }
    }
}

int main()
{
    int n, nrpi = 0, nrpd = 0, k = 0, nro1 = 0, nro0 = 0, i, j;
    fin >> n;
    ciur();
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        if(v[i]%9 == 0)
        {
            nrpd = 0;
            nro0++;
            if(i != n)
                if(!c[v[i-1]] && !c[v[i+1]])
                    nro1++;
            for(j = i+1; j <= n; j++)
            {
                if(!c[v[j]])
                    nrpd++;
                else
                    break;
            }

            if(min(nrpi, nrpd) > k)
                k = min(nrpi, nrpd);

            nrpi = nrpd;
            i = j - 1;
        }
        else if(!c[v[i]])
            nrpi++;
        else
            nrpi = 0;
    }
    fout << nro0 << '\n' << nro1 << '\n' << k;
    return 0;
}
