#include <bits/stdc++.h>

using namespace std;

struct
{
    int f, s;
} v[100001];

int main()
{
    int cer, p, n, i, d, s, c, x, ogx, mn, mx, j;
    cin >> cer >> p >> n;
    if(cer == 1)
    {
        for(i = 1; i <= p; i++)
        {
            cin >> s >> d >> c;
            v[i].f = s;
        }
        cin >> ogx;
        for(i = 2; i <= n; i++)
        {
            cin >> x;
            mn = min(ogx, x);
            mx = max(ogx, x);
            for(j = 1; j <= p; j++)
            {
                if(mn < v[i].f && v[i].f < mx)
                    v[i].s++;
            }
        }
        sort(v+1, v+p+1);
        cout << v[p].s;
    }
    return 0;
}
