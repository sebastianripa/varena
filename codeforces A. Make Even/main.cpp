#include <iostream>

using namespace std;

int main()
{
    int t, n, i, cn;
    bool j = false, u = false;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        j = false;
        u = false;
        cin >> n;
        cn = n;
        while(n)
        {
            if(n/10 == 0 && n%10%2 == 0)
                j = true;
            if(n%10%2 == 0)
                u = true;
            n /= 10;
        }
        if(cn%2 == 0)
            cout << 0 << '\n';
        else
        {
            if(u)
            {
                if(j)
                    cout << 1 << '\n';
                else
                    cout << 2 << '\n';
            }
            else
                cout << -1 << '\n';
        }

    }
    return 0;
}
