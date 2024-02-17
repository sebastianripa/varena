#include <bits/stdc++.h>

using namespace std;

ifstream fin ("br.in");
ofstream fout ("br.out");

long long v[15005];

int main()
{
    long long n, t, k, x, i, j, s = 0, r = 0, ki;
    fin >> n >> t;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= t; i++)
    {
        r = 0;
        s = 0;
        fin >> k >> x;
        ki = k;
        while(s <= x)
        {
            s += v[k];
            if(k == ki+1 && r != 1)
                break;
            if(k == n)
                k = 1;
            else
                k++;
            r++;
        }
        fout << r - 1 << '\n';
    }
    return 0;
}
