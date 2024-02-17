#include <bits/stdc++.h>

using namespace std;

ifstream fin ("munti.in");
ofstream fout ("munti.out");

int main()
{
    long long n, i, imm = 0, a = 0, in = 0, amm = 0, nram = 0, nrim = 0, nrm = 0, y, x;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(x == 0)
        {
            if(a == amm)
                nram++;
            else if(amm < a)
            {
                nram = 1;
                amm = a;
            }
            if(in == imm)
                nrim++;
            else if(imm < in)
            {
                nrim = 1;
                imm = in;
            }
            a = 0;
            in = 0;
        }
        else
        {
            if(y == 0)
                nrm++;
            a += x;
            if(in < x)
                in = x;
        }
        y = x;
    }
    if(a == amm)
        nram++;
    else if(amm < a)
    {
        nram = 1;
        amm = a;
    }
    if(in == imm)
        nrim++;
    else if(imm < in)
    {
        nrim = 1;
        imm = in;
    }
    fout << nrm << '\n' << imm << '\n' << nrim << '\n' << amm << '\n' << nram;
    return 0;
}
