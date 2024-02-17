#include <iostream>

using namespace std;

int main()
{
    int t, n, i = 0, j = 0, k, nri = 1, nrp = 2;
    cin >> t;
    for(k = 1; k <= t; k++)
    {
        nri = 1;
        nrp = 2;
        i = 0;
        j = 0;
        cin >> n;
        if(n == 2)
            cout << -1 << '\n';
        else
        {
            while(nri <= n*n && j != n)
            {
                cout << nri << ' ';
                i++;
                if(i == n+1)
                {
                    cout << '\n';
                    i = 1;
                    j++;
                }
                nri += 2;
            }
            while(nrp <= n*n && j != n)
            {
                cout << nrp << ' ';
                i++;
                if(i == n +1)
                {
                    cout << '\n';
                    i = 1;
                    j++;
                }
                nrp += 2;
            }
            cout << '\n';
        }
    }
    return 0;
}
