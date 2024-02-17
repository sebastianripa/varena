#include <bits/stdc++.h>

using namespace std;

ifstream fin ("proxima.in");
ofstream fout ("proxima.out");

long long vf[10];

int main()
{
    long long cer, x = 0, i, cif = 0, nrc = 0, nrn = 1, s = 0, m = 0;
    char c;
    fin >> cer;
    if(cer == 1)
    {
        while(fin >> c)
            nrc++;
        fout << nrc;
    }
    else if(cer == 2)
    {
        while(fin >> c)
        {
            if(c == '+')
                nrn++;
        }
        fout << nrn;
    }
    else
    {
        while(fin >> c)
        {
            if(c == '*')
                cif++;
            if(c == '|')
            {
                vf[cif]++;
                x = x*10 + cif;
                cif = 0;
            }
            if(c == '+')
            {
                vf[cif]++;
                x = x*10 + cif;
                cif = 0;
                s += x;
                x = 0;
            }
        }
        vf[cif]++;
        x = x*10 + cif;
        cif = 0;
        s += x;
        if(cer == 3)
        {
            for(i = 0; i <= 9; i++)
            {
                if(m < vf[i])
                    m = vf[i];
            }
            if(m == 0)
                cout << 0;
            else
            {
                for(i = 0; i <= 9; i++)
                {
                    if(m == vf[i])
                        fout << i << ' ';
                }
            }
        }
        else
            fout << s;
    }
    return 0;
}
