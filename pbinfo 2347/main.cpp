#include <bits/stdc++.h>

using namespace std;

ifstream fin ("furnici.in");
ofstream fout ("furnici.out");

int d[100005];

int nrdiv(int n)
{
    int i, nrd = 0;
    for(i = 1; i*i < n; i++)
    {
        if(n%i == 0)
            nrd += 2;
    }
    if(i*i == n)
        nrd++;
    return nrd;
}

int main()
{
    int n, x, i, nrs = 0;
    bool ok = false;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        d[i] = nrdiv(x);
    }
    for(i = 1; i <= n-1; i++)
    {
        if(d[i] > d[i+1])
            ok = true;
        else if(ok)
        {
            nrs++;
            ok = false;
        }
    }
    if(ok)
        nrs++;
    fout << nrs;
    return 0;
}
