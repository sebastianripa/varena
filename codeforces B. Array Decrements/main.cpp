#include <iostream>

using namespace std;

long long a[50005], b[50005];

int main()
{
    long long t, n, maxi = 0, o, i, j, m = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        maxi = 0;
        m = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> a[i];
        for(i = 1; i <= n; i++)
            cin >> b[i];
        for(i = 1; i <= n; i++)
        {
            if(b[i] != 0)
            {
                if(maxi == 0)
                    maxi = a[i] - b[i];
                else
                {
                    o = a[i] - b[i];
                    if(maxi != o)
                    {
                        cout << "NO" << '\n';
                        break;
                    }
                }
            }
            else
            {
                o = a[i] - b[i];
                m = max(o, m);
            }
        }
        if(n == 1)
            maxi = a[1] - b[1];
        if(i == n+1)
        {
            if(m > maxi)
                cout << "NO" << '\n';
            else if(maxi < 0)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
    return 0;
}
