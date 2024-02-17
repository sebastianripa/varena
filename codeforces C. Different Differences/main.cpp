#include <iostream>

using namespace std;

int v[50];

int main()
{
    int t, k, n, i, j, nre = 0, x = 1, inc, mx;
    cin >> t;
    while(t--)
    {
        x = 1;
        nre = 0;
        cin >> k >> n;
        for(i = 1; x <= n; i++)
        {
            v[i] = x;
            x += i;
            nre++;
        }
        inc = i - 1;
        x -= inc;
        if(nre < k)
        {
            if(n - x >= k - nre)
            {
                for(i = 1; i <= nre; i++)
                    cout << v[i] << ' ';
                mx = k - nre;
                for(i = 1; i <= mx; i++)
                    cout << x + i << ' ';
                cout << '\n';
                continue;
            }
        }
        else
        {
            for(i = 1; i <= k; i++)
                cout << v[i] << ' ';
            cout << '\n';
            continue;
        }
        inc--;
        while(inc-- >= 1)
        {
            x = 1;
            nre = 0;
            for(i = 1; i <= inc + 1; i++)
            {
                v[i] = x;
                x += i;
                nre++;
            }
            x -= i - 1;
            if(nre < k)
                if(n - x >= k - nre)
                {
                    for(i = 1; i <= nre; i++)
                        cout << v[i] << ' ';
                    mx = k - nre;
                    for(i = 1; i <= mx; i++)
                        cout << x + i << ' ';
                    cout << '\n';
                    break;
                }

        }
    }
    return 0;
}
