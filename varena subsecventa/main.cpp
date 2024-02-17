#include <bits/stdc++.h>

using namespace std;

ifstream fin ("subsecventa.in");
ofstream fout ("subsecventa.out");

int v[10000001];

int main()
{
    int n, nr = 0, i, j, s = 0, k, im, jm = 0, maxi = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        s = 0;
        for(j = i; j <= n; j++)
        {
            s += v[j];
            if(s%n == 0)
            {
                k = j;
                if(k > jm)
                {
                    jm = k;
                    im = i;
                }
            }
        }
    }
    fout << im << ' ' << jm;
    return 0;
}
