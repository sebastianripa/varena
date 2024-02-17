#include <iostream>

using namespace std;

int main()
{
    long long n, m, e, b, x, y, a = 1;
    cin >> n >> m >> e >> b;
    if(n == 0 && m == 0)
        cout << 0 << '\n' << 0;
    else
    {
        x = (m*b+e)/(m - n);
        y = n*x+e;
        cout << y << '\n' << x;
    }

    return 0;
}
