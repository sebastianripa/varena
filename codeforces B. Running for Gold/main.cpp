#include <bits/stdc++.h>

using namespace std;

int v1[100000], v2[100000], v3[100000], v4[100000], v5[100000], a[100000];

int main()
{
    long long t, n, i, j, k, m1 = 1000000, m2 = 1000000, p1, p2;
    cin >> t;
    for(k = 1; k <= t; k++)
    {
        for(i = 1; i <= 5; i++)
            a[i] = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v1[i] >> v2[i] >> v3[i] >> v4[i] >> v5[i];
        if(n == 1)
            cout << 1 << '\n';
        else if(n == 2 || n == 3)
        {
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v1[i])
                {
                    m1 = v1[i];
                    p1 = i;
                }
            }
            a[p1]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v2[i])
                {
                    m1 = v2[i];
                    p1 = i;
                }
            }
            a[p1]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v3[i])
                {
                    m1 = v3[i];
                    p1 = i;
                }
            }
            a[p1]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v4[i])
                {
                    m1 = v4[i];
                    p1 = i;
                }
            }
            a[p1]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v5[i])
                {
                    m1 = v5[i];
                    p1 = i;
                }
            }
            a[p1]++;
            if(a[p1] == 5)
                cout << p1 << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v1[i])
                {
                    m1 = v1[i];
                    p1 = i;
                }
            }
            for(i = 1; i <= n; i++)
            {
                if(m2 > v1[i] && v1[i] != m1)
                {
                    m2 = v1[i];
                    p2 = i;
                }
            }
            a[p1]++;
            a[p2]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v2[i])
                {
                    m1 = v2[i];
                    p1 = i;
                }
            }
            for(i = 1; i <= n; i++)
            {
                if(m2 > v2[i] && v2[i] != m1)
                {
                    m2 = v2[i];
                    p2 = i;
                }
            }
            a[p1]++;
            a[p2]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v3[i])
                {
                    m1 = v3[i];
                    p1 = i;
                }
            }
            for(i = 1; i <= n; i++)
            {
                if(m2 > v3[i] && v3[i] != m1)
                {
                    m2 = v3[i];
                    p2 = i;
                }
            }
            a[p1]++;
            a[p2]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v4[i])
                {
                    m1 = v4[i];
                    p1 = i;
                }
            }
            for(i = 1; i <= n; i++)
            {
                if(m2 > v4[i] && v4[i] != m1)
                {
                    m2 = v4[i];
                    p2 = i;
                }
            }
            a[p1]++;
            a[p2]++;
            m1 = 1000000;
            m2 = 1000000;
            for(i = 1; i <= n; i++)
            {
                if(m1 > v5[i])
                {
                    m1 = v5[i];
                    p1 = i;
                }
            }
            for(i = 1; i <= n; i++)
            {
                if(m2 > v5[i] && v5[i] != m1)
                {
                    m2 = v5[i];
                    p2 = i;
                }
            }
            a[p1]++;
            a[p2]++;
            m1 = 0;
            for(i = 1; i <= 5; i++)
            {
                if(m1 < a[i])
                    m1 = i;
            }
            cout << m1 << '\n';
        }

    }
    return 0;
}
