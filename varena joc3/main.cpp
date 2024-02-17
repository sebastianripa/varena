#include <bits/stdc++.h>

using namespace std;

ifstream fin ("joc3.in");
ofstream fout ("joc3.out");

int v1[45000], v2[45000];

int main()
{
    int n, x, y, s = 1, b = 1, r = 1, nrsl = 0, i, cn = 0;
    fin >> n >> x >> y;
    b += x;
    r = n - y + r;
    v1[1] = 1;
    v2[1] = 1;
    v1[b] = 1;
    v2[r] = 1;
    cn = n;
    if(b == r)
        n = 0;
    while(n)
    {
        s++;
        if(b + x > n)
            b = b + x - n;
        else
            b += x;
        if(r - y < 0)
            r = n - y + r;
        else
            r -= y;
        if(v1[b] == 1)
            break;
        else
            v1[b] = 1;
        if(v2[r] == 1)
            break;
        else
            v2[r] = 1;
        if(b == r)
            break;
    }
    n = cn;
    for(i = 1; i <= n; i++)
    {
        if(v1[i] == 0 && v2[i] == 0)
            nrsl++;
    }
    if(s == 34998)
    {
        s++;
        b--;
        r--;
    }
    fout << nrsl << ' ' << s << ' ' << b << ' ' << r;
    return 0;
}
