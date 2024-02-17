#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cifrevecine.in");
ofstream fout ("cifrevecine.out");

int main()
{
    long long n, k, i, j, o = 1, p, x, xmax = 0, m, b = 0;
    fin >> n >> k;
    m = n;
    while(m)
    {
        b++;
        m /= 10;
    }
    for(i = 1; i <= k; i++)
        o *= 10;
    p = 1;
    for(i = 1; i <= b-k+1; i++)
    {
        x = n/(o*p)*p+n%p;
        p *= 10;
        if(x > xmax)
            xmax = x;
    }
    fout << xmax;
    return 0;
}
