#include <iostream>

using namespace std;

int main()
{
    int n, t, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> n;
        if(n%3 == 0)
            cout << n/3 << ' ' << n/3 + 1 << ' ' << n/3 - 1;
        else if(n%3 == 1)
            cout << n/3 << ' ' << n/3 + 2 << ' ' << n/3 - 1;
        else
            cout << n/3 + 1 << ' ' << n/3 + 2 << ' ' << n/3 - 1;
        cout << '\n';
    }
    return 0;
}
