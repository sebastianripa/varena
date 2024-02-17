#include <iostream>

using namespace std;

char v1[21], v2[21];

int main()
{
    int t, n, m, i, j, i1, j1;
    bool ok1 = true, ok2 = true;
    cin >> t;
    while(t--)
    {
        ok1 = true;
        ok2 = true;
        cin >> n >> m;
        cin.get();
        for(i = 1; i <= n; i++)
            cin.get(v1[i]);
        cin.get();
        for(j = 1; j <= m; j++)
            cin.get(v2[j]);
        for(i = 2; i <= n; i++)
        {
            if(v1[i] == v1[i-1])
            {
                ok1 = false;
                i1 = i;
                break;
            }
        }
        for(j = 2; j <= m; j++)
        {
            if(v2[j] == v2[j-1])
            {
                ok2 = false;
                j1 = j;
                break;
            }
        }
        if(!ok1 && !ok2)
        {
            cout << "NO" << '\n';
            continue;
        }
        if(!ok1)
        {
            if(v1[n] == v2[m])
            {
                cout << "NO" << '\n';
                continue;
            }
            for(i = i1 + 1; i <= n; i++)
            {
                if(v1[i] == v1[i-1])
                {
                    cout << "NO" << '\n';
                    ok1 = true;
                    break;
                }
            }
            if(ok1)
                continue;
            cout << "YES" << '\n';
        }
        else if(!ok2)
        {
            if(v2[m] == v1[n])
            {
                cout << "NO" << '\n';
                continue;
            }
            for(j = j1 + 1; j <= m; j++)
            {
                if(v2[j] == v2[j-1])
                {
                    cout << "NO" << '\n';
                    ok2 = true;
                    break;
                }
            }
            if(ok2)
                continue;
            cout << "YES" << '\n';
        }
        else
            cout << "YES" << '\n';
    }
    return 0;
}
