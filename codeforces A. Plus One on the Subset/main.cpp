#include <iostream>

using namespace std;

int main()
{
    long long t, n, x, mini = 999999999, maxi = 0, j, i;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        maxi = -999999999;
        mini = 999999999;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        cout << maxi - (mini) << '\n';
    }
    return 0;
}
