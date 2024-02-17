#include <iostream>

using namespace std;

long long v[1005];

int main()
{
    long long t, n, i, j, maxi = 0, k, l, aux, ans = 0;
    cin >> t;
    for(l = 1; l <= t; l++)
    {
        maxi = 0;
        ans = 0;
        cin >> n >> k;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = 1; i <= k; i++)
        {
            maxi = 0;
            for(j = i; j <= n; j += k)
                maxi = max(v[j], maxi);
            ans += maxi;
        }
        cout << ans << '\n';
    }
    return 0;
}
