#include <iostream>

using namespace std;

char v[2005];

int main()
{
    int t, n, i, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin.get(v[0]);
        for(i = 1; i <= n; i++)
            cin.get(v[i]);
        ans = n;
        for(i = 1; v[i] != v[n] && i <= n; i++, n--)
            ans -= 2;
        cout << ans << '\n';
    }
    return 0;
}
