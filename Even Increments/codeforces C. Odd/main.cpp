#include <iostream>

using namespace std;

int v[55];

int main()
{
    int t, n, i, j;
    bool o = false, e = false;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        o = false;
        e = false;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i]%2 == 1)
                o = true;
        }
        if(o == false)
        {
            cout << "YES" << '\n';
            continue;
        }
        for(i = 1; i <= n; i++)
        {
            if(v[i]%2 == 0)
                e = true;
        }
        if(e == false)
        {
            cout << "YES" << '\n';
            continue;
        }
        o = false;
        e = false;
        if(v[1]%2 == 0)
            e = true;
        else
            o = true;
        for(i = 2; i <= n; i++)
        {
            if(v[i]%2 == 0)
            {
                if(e == true)
                {
                    cout << "NO" << '\n';
                    break;
                }
                else
                {
                    o = false;
                    e = true;
                }
            }
            else
            {
                if(o == true)
                {
                    cout << "NO" << '\n';
                    break;
                }
                else
                {
                    o = true;
                    e = false;
                }
            }
        }
        if(i == n+1)
            cout << "YES" << '\n';
    }
    return 0;
}
