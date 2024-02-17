#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, l, r, x, a, b, i, j, ans = 0;
    bool ok = true;
    cin >> t;
    while(t--)
    {
        ok = true;
        ans = 0;
        cin >> l >> r >> x >> a >> b;
        if(a == b)
        {
            cout << 0 << '\n';
            continue;
        }
        if(b + x > r && b - x < l)
        {
            cout << -1 << '\n';
            continue;
        }
        if(max(b, a) - min(b, a) >= x)
        {
            cout << 1 << '\n';
            continue;
        }
        while(a != b)
        {
            if(b > a)
            {
                if(b + x <= r)
                {
                    b += x;
                    ans++;
                }
                else if(a - x >= l)
                {
                    a -= x;
                    ans++;
                }
                else if(b - x >= l)
                {
                    b -= x;
                    ans++;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if(a + x <= r)
                {
                    a += x;
                    ans++;
                }
                else if(b - x >= l)
                {
                    b -= x;
                    ans++;
                }
                else if(a - x >= l)
                {
                    a -= x;
                    ans++;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if(max(b, a) - min(b, a) >= x)
            {
                ans++;
                break;
            }
        }
        if(!ok)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}
