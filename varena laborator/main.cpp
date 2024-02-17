#include <bits/stdc++.h>

using namespace std;

ifstream fin ("laborator.in");
ofstream fout ("laborator.out");

int va[100], vb[100];

int main()
{
    long long n, a, b, nra = 0, nrs = 0, nrm = 0, nr = 0, i = 1;
    bool ok = false;
    fin >> n >> a >> b;
    while(a != 0)
    {
        va[i] = a%2;
        i++;
        a /= 2;
    }
    i = 1;
    while(b != 0)
    {
        vb[i] = b%2;
        i++;
        b /= 2;
    }
    for(i = 1; i <= n; i++)
    {
        if(va[i] == 1 && vb[i] == 0)
        {
            nrs++;
            ok = false;
        }
        else if(va[i] == 0 && vb[i] == 1)
        {
            nra++;
            ok = false;
        }
        else if(va[i] == 1 && vb[i] == 1)
        {
            nr++;
            ok = true;
        }
        else
            nr = 0;
        if(ok == false)
        {
            if(nr > nrm)
                nrm = nr;
            nr = 0;
        }

    }
    if(nr > nrm)
        nrm = nr;
    fout << nrs << ' ' << nra << ' ' << nrm;
    return 0;
}
