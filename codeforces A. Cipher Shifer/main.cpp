#include <iostream>

using namespace std;

char v[101];

int main()
{
    int t, n, i, j;
    char sc;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin.get();
        for(i = 1; i <= n; i++)
            cin.get(v[i]);
        for(i = 1; i <= n; i++)
        {
            sc = v[i];
            for(j = 1; j <= n && v[i+j] != v[i]; j++)
                continue;
            cout << v[i];
            if(j == n+1)
                continue;
            else
                i += j;
        }
        cout << '\n';
    }
    return 0;
}
