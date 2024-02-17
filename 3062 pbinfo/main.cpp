#include <iostream>

using namespace std;

int main()
{
    int x, t, y, m = 0;
    cin >> x >> t >> y;
    while(x > y)
    {
        x -= x/4;
        m += t;
    }
    cout << m;
    return 0;
}
