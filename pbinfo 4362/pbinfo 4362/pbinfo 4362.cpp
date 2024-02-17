#include <iostream>

using namespace std;

int v[100005];

int main()
{
    int n, q, i, j, nre = 0, ad, np, l, r, s = 0, vr, ctp;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] != 0)
            nre++;
    }
    if (nre % 2 == 0)
    {
        ad = nre;
        np = n + 1;
    }
    else
    {
        ad = nre + 1;
        np = n + 2;
    }
    for (i = 1; i <= q; i++)
    {
        cin >> l >> r;
        if (nre % 2 == 0)
        {
            if (l == 1)
            {
                if (r <= n)
                    for (j = 1; j <= r; j++)
                        s += v[j];
                else
                {
                    vr = r - n;
                    for (j = 1; j <= n; j++)
                        s += v[j];
                    ctp = vr / n;
                    s = s + (ctp * (n + nre * (ctp + 1) / 2));

                }
            }
        }
    }
}

