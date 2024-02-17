#include <iostream>

using namespace std;

int main()
{
    int t, n, sf = 0, x, y, z, a, b, m, si;
    cin >> t >> n >> x >> y;
    a = x;
    b = y;
    while(a != b)
    {
        if(a > b)
            a -= b;
        else if(a < b)
            b -= a;
    }
    m = (x*y)/a;
    sf = n - (n/x + n/y - n/m);
    if(t == 1)
        cout << sf << '\n';
    else
    {
        cin >> z;
        n = n/z;
        si = n - (n/x + n/y - n/m);
        cout << sf - si;
    }
    return 0;
}
