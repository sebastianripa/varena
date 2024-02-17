#include <iostream>

using namespace std;

int main()
{
    int t, n, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        if(n < 2020h)
            cout << "NO" << '\n';
        else
        {
            while(n%2021 != 0 && n > 2020)
                n -= 2020;
            if(n < 2020)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
    return 0;
}
