#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, i, x, ans = 0, s = 0;
    bool ok = false;
    cin >> t;
    while(t--)
    {
        ok = false;
        ans = 0;
        s = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x < 0 && !ok)
                ok = true;
            if(ok && x > 0)
            {
                ans++;
                ok = false;
            }
            s += fabs(x);
        }
        if(ok)
            ans++;
        cout << s << ' ' << ans << '\n';
    }
    return 0;
}
