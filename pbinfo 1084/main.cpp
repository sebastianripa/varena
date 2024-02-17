#include <bits/stdc++.h>

using namespace std;

ifstream fin ("tren.in");
ofstream fout ("tren.out");

int main()
{
    int n, l, h, m, s, i, nr1 = 0, nr2 = 0, fn, nr = 0, ma, sa, d, dm = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> l >> h >> m >> s;
        if(l == 1)
            nr1++;
        else
            nr2++;
        if(l == 2)
        {
            if(ma > m)
                nr++;
            else if(ma+sa < m+s)
                nr++;
        }
        else
        {
            ma = m;
            sa = s;
        }
        if(i != 1)
        {
            d = m - fn - 1;
            fn = m+s;
        }
        else
            fn = m+s;
        dm = max(dm, d);
    }
    fout << max(nr1, nr2) << ' ' << nr + nr1 << ' ' << dm;
    return 0;
}
