#include <iostream>

using namespace std;

int v[100005];

int main()
{
    long long t, n, q, i, j, p = 0, imp = 0, px, x, s;
    cin >> t;
    while(t--)
    {
        s = 0;
        p = 0;
        imp = 0;
        cin >> n >> q;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i]%2 == 0)
                p++;
            else
                imp++;
            s += v[i];
        }
        for(i = 1; i <= q; i++)
        {
            cin >> px >> x;
            if(px == 1)
            {
                s = s + imp*x;
                if(x%2 == 1)
                {
                    p += imp;
                    imp -= imp;
                }
            }
            else
            {
                s = s + p*x;
                if(x%2 == 1)
                {
                    imp += p;
                    p -= p;
                }
            }
            cout << s << '\n';
        }
    }
    return 0;
}
