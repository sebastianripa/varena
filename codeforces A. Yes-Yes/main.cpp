#include <iostream>

using namespace std;

char v[55];

int main()
{
    int t, n, i, j;
    char c;
    bool ok = false;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        ok = false;
        n = 0;
        i = 1;
        if(j == 1)
            cin.get(c);
        cin >> v;
        if(n < 3)
        {
            cout << "NO" << '\n';
            continue;
        }
        for(i = 3; i <= n; i++)
        {
            if(ok && v[i] == 's')
            {
                ok = false;
                continue;
            }
            if(v[i-2] == 'Y' && v[i-1] == 'e' && v[i] == 's')
                ok = true;
        }
    }
    return 0;
}
