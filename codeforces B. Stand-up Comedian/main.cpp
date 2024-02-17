#include <iostream>

using namespace std;

int main()
{
    int t, a1, a2, a3, a4, m1 = 0, m2 = 0, ans = 0;
    cin >> t;
    while(t--)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        m1 += a1;
        m2 += a1;
        ans += a1;
        if(a2 <= a3)
        {
            m1 -= a1;
            m2 += a1;
            a3 -= a1;
            ans += a1;
            if(a3 < a2)
            {
                ans += (a1*2)*(a3/(a1*2))*2;
                a2 -= (a1*2)*(a3/(a1*2));
                a3 -= (a1*2)*(a3/(a1*2));
                if(m2 - a3 < 0)
                {
                    ans += m2 + 1;
                    cout << ans << '\n';
                    continue;
                }
                ans += a3;
                a3 = 0;
                m2 -= a3;
                m1 += a3;
                ans += m1+1;
                a2 -= m1;
                m1 -= m1;
                cout << ans << '\n';
            }
            ans += (a1*2)*(a2/(a1*2))*2;
            a3 -= (a1*2)*(a2/(a1*2));
            a2 -= (a1*2)*(a2/(a1*2));
            if(m2 - a2 < 0)
            {
                ans += m2 + 1;
                cout << ans << '\n';
                continue;
            }
            ans += a2;
            a2 = 0;
            m2 -= a2;
            m1 += a2;
            ans += m1+1;
            a3 -= m1;
            m1 -= m1;
            cout << ans << '\n';
            continue;
        }
        m2 -= a1;
        m1 += a1;
        a2 -= a1;
        ans += a1;
        if(a2 < a3)
        {
            ans += (a1*2)*(a2/(a1*2))*2;
            a2 -= (a1*2)*(a2/(a1*2));
            a3 -= (a1*2)*(a2/(a1*2));
            if(m1 - a3 < 0)
            {
                ans += m2 + 1;
                cout << ans << '\n';
                continue;
            }
            ans += a2;
            a2 = 0;
            m1 -= a2;
            m2 += a2;
            ans += m2+1;
            a3 -= m2;
            m1 -= m2;
            cout << ans << '\n';
        }
        ans += (a1*2)*(a3/(a1*2))*2;
        a2 -= (a1*2)*(a3/(a1*2));
        a3 -= (a1*2)*(a3/(a1*2));
        if(m1 - a3 < 0)
        {
            ans += m1 + 1;
            cout << ans << '\n';
            continue;
        }
        ans += a3;
        a3 = 0;
        m1 -= a3;
        m2 += a3;
        ans += m2+1;
        a2 -= m2;
        m2 -= m2;
        cout << ans << '\n';
    }
    return 0;
}
