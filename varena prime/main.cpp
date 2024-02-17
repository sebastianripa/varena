#include <bits/stdc++.h>

using namespace std;

ifstream fin ("prime.in");
ofstream fout ("prime.out");

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

int main()
{
    long long n, k, s = 0, cn;
    fin >> n >> k;
    cn = n;
    while(!prim(cn))
        cn--;
    fout << cn << '\n';
    while(k)
    {
        if(prim(++n))
        {
            s += n;
            k--;
        }
    }
    fout << s;
    return 0;
}
