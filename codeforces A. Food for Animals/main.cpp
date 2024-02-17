#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c, x, y, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b >> c >> x >> y;
        x -= a;
        y -= b;
        if(x < 0)
            x += fabs(x);
        if(y < 0)
            y += fabs(y);
        if(x + y <= c)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
