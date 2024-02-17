#include <iostream>

using namespace std;

int vf[200005];

int main()
{
    int t, n, x, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            vf[x]++;
        }
        for(i = 1; i <= n; i++)
        {
            if(vf[i] >= 3)
            {
                cout << i << '\n';
                break;
            }
        }
        if(i == n + 1)
            cout << -1 << '\n';
        for(i = 1; i <= n; i++)
            vf[i] = 0;
    }
    return 0;
}
