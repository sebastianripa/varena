#include <bits/stdc++.h>

using namespace std;

long long v[200005];

int main()
{
    long long t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        sort(v+1, v+n+1);
        cout << max(v[1]*v[2], v[n]*v[n-1]) << '\n';
    }
    return 0;
}
