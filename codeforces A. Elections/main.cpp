#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c, i;
    cin >> t;
    for(i = 1; i<= t; i++)
    {
        cin >> a >> b >> c;
        if(a > b && a > c)
            cout << 0 << ' ' << a - b + 1 << ' ' << a - c + 1 << '\n';
        else if(b > a && b > c)
            cout << b - a + 1 << ' ' << 0 << ' ' << b - c + 1 << '\n';
        else if(c > a && c > b)
            cout << c - a + 1 << ' ' << c - b + 1 << ' ' << 0 << '\n';
        else if(a == c && a > b)
            cout << 1 << ' ' << a - b + 1 << ' ' << 1 << '\n';
        else if (a == b && a > c)
            cout << 1 << ' ' << 1 << ' ' << a - c + 1 << '\n';
        else if(b == c && b > a)
            cout << b - a + 1 << ' ' << 1 << ' ' << 1 << '\n';
        else
            cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
    }
    return 0;
}
