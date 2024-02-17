#include <iostream>

using namespace std;

int v[101];

int main()
{
    int t, n, y = 0, z = 0, i, j;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> n;
        for(j = 1; j <= n; j++)
        {
            cin >> v[j];
            if(y != v[j])
                y = v[j];
        }
        for(j = 1; j <= n; j++)
        {
            if(v[j] != y)
            {
                if(v[n] == y && v[n] != v[n-1] && v[n] != v[n-2])
                    cout << n << '\n';
                else
                    cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}
