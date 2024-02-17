#include <bits/stdc++.h>

using namespace std;

int v[51];

int main()
{
    int t, n, ans = 0, i;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        sort(v+1, v+n+1);
        for(i = 1; i <= n/2; i++)
            ans += v[n-i+1] - v[i];
        cout << ans << '\n';
    }
    return 0;
}
