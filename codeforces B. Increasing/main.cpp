#include <bits/stdc++.h>

using namespace std;

long long v[105];

int main()
{
    long long t, n, x, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            v[i] = x;
        }
        sort(v+1, v+n+1);
        for(i = 2; i <= n; i++)
        {
            if(v[i] == v[i-1])
                break;
        }
        if(i == n + 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
