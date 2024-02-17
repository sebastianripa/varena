#include <iostream>

using namespace std;

int v[200001];

int main()
{
    int t, n, mini, mmini = INT_MIN, i, j, poz;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        mmini = INT_MIN;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        while(n > 1)
        {
            mini = v[1];
            poz = 1;
            for(i = 1; i <= n; i++)
            {
                if(mini > v[i])
                {
                    mini = v[i];
                    poz = i;
                }
            }
            n--;
            for(i = poz; i <= n; i++)
                v[i] = v[i+1];
            for(i = 1; i <= n; i++)
                v[i] -= mini;
            mmini = max(mini, mmini);
        }
        mini = v[1];
        mmini = max(mmini, mini);
        cout << mmini << '\n';
    }
    return 0;
}
