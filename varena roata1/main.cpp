#include <bits/stdc++.h>

using namespace std;

ifstream fin ("roata1.in");
ofstream fout ("roata1.out");

long long v[50001], vp[50001];

int main()
{
    long long n, np = 0, npp, i, j, p, c;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
        vp[v[i]] = i;
    }
    for(i = 1; i <= n; i++)
    {
        if(i == 1)
            np = n - vp[i] + 1;
        else
        {
            c = npp/n;
            if(c == 0)
                np = n - vp[i] + 1;
            else
                np = n - vp[i] + 1 + n*c;
            if(np <= npp)
                np += n;
        }
        fout << np << ' ';
        npp = np;
        for(j = 1; j <= n; j++)
        {
            vp[j] = vp[j] + np%n;
            if(vp[j]%n != 0)
                vp[j] %= n;
            else
                vp[j] = n;
        }
    }
    return 0;
}
