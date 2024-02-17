#include <iostream>

using namespace std;

int v[200005];

int main()
{
    int t, n, q, i, l, r, nr, x, s = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            v[i] = v[i-1] + x;
        }
        for(i = 1; i <= q; i++)
        {
            s = 0;
            cin >> l >> r >> nr;
            s += v[n];
            s -= v[r];
            s += v[l-1];
            s += (nr*(r - l + 1));
            if(s%2 == 0)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
    return 0;
}
