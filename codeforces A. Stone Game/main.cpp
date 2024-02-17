#include <iostream>

using namespace std;

int main()
{
    int t, n, pmin, pmax, mini = 101, maxi = 0, i, j, x, mij, s = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        maxi = 0;
        mini = 101;
        s = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(maxi < x)
            {
                maxi = x;
                pmax = i;
            }
            if(mini > x)
            {
                mini = x;
                pmin = i;
            }
        }
        if(pmin > pmax) swap(pmin, pmax);
            cout << min(n-pmin+1, min(pmax, pmin+n - pmax+1)) << '\n';
    }
    return 0;
}
