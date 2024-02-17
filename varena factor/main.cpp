#include <bits/stdc++.h>

using namespace std;

ifstream fin ("factor.in");
ofstream fout ("factor.out");

bool prim(int n)
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

int descompus(int n)
{
    int fp = 2, p = 0, pm = 0, fpm = 0, uc;
    while(n != 1)
    {
        p = 0;
        while(n%fp == 0)
        {
            n /= fp;
            p++;
        }
        if(pm < p)
        {
            pm = p;
            fpm = fp;
        }
        else if(pm == p)
        {
            if(fp > fpm)
                fpm = fp;
        }
        if(prim(n))
        {
            p = 1;
            fp = n;
            if(pm < p)
            {
                pm = p;
                fpm = fp;
            }
            else if(pm == p)
            {
                if(fp > fpm)
                    fpm = fp;
            }
            n /= n;
        }
        fp++;
    }
    uc = fpm%10;
    return uc;
}

int main()
{
    int n, nrd, gigel = 0;
    fin >> n;
    nrd = descompus(n);
    while(n)
    {
        if(n%10 == nrd%10)
            gigel++;
        n /= 10;
    }
    fout << gigel;
    return 0;
}
