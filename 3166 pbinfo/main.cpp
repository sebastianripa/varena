#include <iostream>

using namespace std;

int main()
{
    long double x;
    long long  t, y, i, tr = 0;
    cin >> x >> t >> y >> i;
    while(x >= y)
    {
        x -= x/i;
        tr += t;
    }
    if(tr == 0)
        cout << t;
    else
        cout << tr;
    return 0;
}
