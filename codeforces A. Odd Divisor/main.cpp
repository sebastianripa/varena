#include <iostream>

using namespace std;

int main()
{
    unsigned long long t, n, i, j;
    bool dipar = false;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        if(n%2 == 1)
            cout << "YES" << '\n';
        else
        {
            while(n%2 == 0)
                n /= 2;
            if(n == 1)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
    return 0;
}
