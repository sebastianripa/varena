#include <bits/stdc++.h>

using namespace std;

ifstream fin ("iepuras2.in");
ofstream fout ("iepuras2.out");

long long vf[10000];

int main()
{
    long long c, n, x, i, ma = 0, mi = 0, j, p = 1, jum, cc, r = 0, la, x2, r2;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            ma = 0;
            mi = 0;
            p = 1;
            for(j = 0; j <= 9; j++)
                vf[j] = 0;
            fin >> x;
            while(x)
            {
                vf[x%10] = 1;
                x /= 10;
            }
            for(j = 9; j >= 0; j--)
            {
                if(vf[j] == 1)
                    ma = ma*10 + j;
            }
            for(j = 1; j <= 10; j++)
            {
                if(vf[j] == 1)
                {
                    mi = mi*10 + j;
                    p *= 10;
                }
            }
            if(vf[0] == 1)
            {
                p /= 10;
                jum = mi%p;
                mi /= p;
                mi *= 10;
                mi *= p;
                mi += jum;
            }
            fout << mi + ma << '\n';
        }
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            r = 0;
            j = 1;
            fin >> x;
            cc = x%9;
            if(cc == 0)
                cc = 9;
            j++;
            vf[j] = 1;
            j++;
            if(x >= 100)
            {
                r += 20;
                x2 = x/1000;
                la = 20;
                vf[j] = la;
                j++;
                p = 100;
                while(x2)
                {
                    r *= 9;
                    r += la + p;
                    x2 /= 10;
                    la = r;
                    vf[j] = la;
                    j++;
                    p *= 10;
                }
                r *= 9;
                r += la + p;
                j--;
                while(p > 1)
                {
                    if(x/p%10 < cc)
                    {
                        r -= (vf[j] + p);
                        r -= vf[j]*(10 - x/p%10 - 2);
                    }
                    else if(x/p%10 > cc)
                        r -= vf[j]*(10 - x/p%10 - 1);
                    else
                    {
                        r -= ((cc+1)*p - x%(p*10) - 1);
                        r -= vf[j]*(10 - x/p%10 - 1);
                    }
                    p /= 10;
                    j--;
                }
                if(x%10 < cc)
                    r--;
                fout << r << '\n';
            }
        }
    }
    return 0;
}
