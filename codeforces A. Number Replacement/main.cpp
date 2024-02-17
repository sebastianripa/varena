#include <iostream>

using namespace std;

int v[51];
char cf[51], c[51];

int main()
{
    int t, n, i, j;
    bool ok = true;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        ok = true;
        for(i = 1; i <= 50; i++)
            cf[i] = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        cin >> c;
        for(i = 1; i <= n; i++)
        {
            if(cf[v[i]] == 0)
                cf[v[i]] = c[i-1];
            else
            {
                if(cf[v[i]] == c[i-1])
                    cf[v[i]] = c[i-1];
                else
                    ok = false;
            }
            if(!ok)
                break;
        }
        if(i == n + 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
