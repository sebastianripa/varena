#include <iostream>

using namespace std;

int main()
{
    int n, x, y, v;
    cin >> n >> x >> y >> v;
    cout << y + (x - 1)*n << ' ';
    if(v%n == 0)
        cout << v/n << ' ' << 4;
    else
    {
        cout << (v - v%n)/4 + 1 << ' ' << v%n;
    }
    return 0;
}
