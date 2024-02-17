#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cufere.in");
ofstream fout ("cufere.out");

int vf[100];

bool prim (int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int cer, n, x, i, j, e, nre = 0;
    bool ok = false;
    fin >> cer >> n;
    for(i = 1; i <= n*27; i++)
    {
        fin >> x;
        if(x != 0)
            vf[x%100] += x/100;
    }
    if(cer == 1)
    {
        for(i = 1; i <= 99; i++)
        {
            if(vf[i] != 0)
                fout << i << ' ' << vf[i] << '\n';
        }
    }
    else
    {
        for(i = 1; i <= 99; i++)
        {
            if(vf[i] != 0)
            {
                ok = prim(i);
                if(ok)
                {
                    for(j = 1; j <= vf[i]/16; j++)
                    {
                        fout << 16 << i << ' ';
                        nre++;
                        if(nre%9 == 0)
                            fout << '\n';
                    }
                    if(vf[i]%16 != 0)
                    {
                        fout << vf[i]%16 << i << ' ';
                        nre++;
                        if(nre%9 == 0)
                            fout << '\n';
                    }
                }
                else
                {
                    for(j = 1; j <= vf[i]/64; j++)
                    {
                        fout << 64 << i << ' ';
                        nre++;
                        if(nre%9 == 0)
                            fout << '\n';
                    }
                    if(vf[i]%64 != 0)
                    {
                        fout << vf[i]%64 << i << ' ';
                        nre++;
                        if(nre%9 == 0)
                            fout << '\n';
                    }
                }
            }
        }
        while(nre++ < n*27)
        {
            fout << 0 << ' ';
            if(nre%9 == 0)
                fout << '\n';
        }
    }
    return 0;
}
