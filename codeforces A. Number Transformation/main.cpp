#include <iostream>

using namespace std;

int main()
{
    int x, y, t, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> x >> y;
        if(y%x != 0)
            cout << 0 << ' ' << 0 << '\n';
        else
            cout << 1 << ' ' << y/x << '\n';
    }
    return 0;
}
