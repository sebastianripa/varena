#include <iostream>

using namespace std;

int v[200001];

int main()
{
    int t, n, s = 0, k, i, j, nr;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        k = 0;
        s = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            s += v[i];
        }
        if(s%n != 0)
            cout << -1 << '\n';
        else
        {
            nr = s/n;
            for(i = 1; i <= n; i++)
            {
                if(v[i] > nr)
                    k++;
            }
            cout << k << '\n';
        }
    }
    return 0;
}
