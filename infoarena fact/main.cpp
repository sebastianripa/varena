#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

ifstream fin ("fact.in");
ofstream fout ("fact.out");

ull zc(ull n)
{
    ull p = 5, r = 0;
    while(n > p)
    {
        r += n/p;
        p *= 5;
    }
    return r;
}

int main()
{
    ull p, l, r, m, zcn;
    fin >> p;
    l = 1;
    r = 10000000000;
    while(l < r)
    {
        m = (l + r)/2;
        if(zc(m) < p)
            l = m + 1;
        else if(zc(m) > p)
            r = m + 1;
        else
            break;
    }
    zcn = zc(m);
    while(zc(m) == zcn && m >= 1)
        m--;
    fout << m + 1;
    return 0;
}
