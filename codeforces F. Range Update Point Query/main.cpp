#include <iostream>

using namespace std;

int v[200005];

int main()
{
    int t, n, q, cer, l, r, x, sc = 0, i, j, ce;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = 1; i <= q; i++)
        {
            cin >> cer;
            if(cer == 1)
            {
                cin >> l >> r;
                for(j = l; j <= r; j++)
                {
                    ce = v[j];
                    while(ce)
                    {
                        sc += ce%10;
                        ce /= 10;
                    }
                    v[j] = sc;
                    sc = 0;
                }
            }
            else
            {
                cin >> x;
                cout << v[x] << '\n';
            }
        }
    }
    return 0;
}
