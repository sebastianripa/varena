#include <iostream>

using namespace std;

int main()
{
    int t, n, l, r, i, j, m, lm, ls, cls, oglm;
    cin >> t;
    while(t--)
    {
        cin >> n >> r >> l;
        m = r - l;
        if(r%m == 0)
        {
            if(r/m == n)
            {
                for(i = 1; i <= n; i++)
                    cout << m << ' ';
                cout << '\n';
                continue;
            }
        }
        else
        {
            if(r/m+1 == n)
            {
                for(i = 1; i <= n-1; i++)
                    cout << m << ' ';
                cout << r%m << '\n';
                continue;
            }
        }
        lm = m - 1;
        if(r%m != 0)
            n--;
        n--;
        ls = r/m - 1;
        cls = ls;
        while(ls < n)
        {
            ls += cls;
            oglm = lm;
            lm--;
        }
        cout << m << ' ';
        if(r%m != 0)
            cout << r%m << ' ';
        for(i = 1; i <= ls - n; i++)
        {
            for(j = 1; j <= ls/cls-2; j++)
                cout << 1 << ' ';
            cout << oglm+1 << ' ';
        }
        n -= (ls - n);
        n = n/(ls/cls);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= ls/cls-1; j++)
                cout << 1 << ' ';
            cout << oglm;
        }
        cout << '\n';
    }
    return 0;
}
