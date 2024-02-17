#include <iostream>

using namespace std;

long long v[1000005];

int main()
{
    long long t, n, i, j, m = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        m = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = n-1; i >= 1; i--)
        {
            while(v[i] >= v[i+1])
            {
                v[i] /= 2;
                m++;
            }
            if(v[i] == 0 && i > 1)
            {
                cout << -1 << '\n';
                break;
            }
        }
        if(i == 0)
            cout << m << '\n';
    }
    return 0;
}
