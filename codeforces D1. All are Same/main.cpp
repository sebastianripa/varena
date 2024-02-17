#include <bits/stdc++.h>

using namespace std;

long long v[100];

int main()
{
    long long t, n, i, a = 0, b = 0, r, j, mini = INT_MAX;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        a = 0;
        b = 0;
        mini = INT_MAX;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            mini = min(mini, v[i]);
        }
        for(i = 1; i <= n; i++)
            v[i] -= mini;
        for(i = 1; i <= n; i++)
        {
            if(v[i] != 0)
            {
                if(a == 0)
                    a = v[i];
                else if(a != b)
                {
                    b = v[i];
                    while(b != 0)
                    {
                      r = a % b;
                      a = b;
                      b = r;
                    }
                }
            }
        }
        if(a == 0)
            cout << -1 << '\n';
        else
            cout << a << '\n';
    }
    return 0;
}
