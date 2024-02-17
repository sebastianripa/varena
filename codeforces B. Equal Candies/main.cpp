#include <iostream>

using namespace std;

int v[55];

int main()
{
    int t, n, j, i, sd, mini = 10000000;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        sd = 0;
        mini = 10000000;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            mini = min(v[i], mini);
        }
        for(i = 1; i <= n; i++)
            sd += (v[i] - mini);
        cout << sd << '\n';
    }
    return 0;
}
