#include <iostream>

using namespace std;

int main()
{
    long long t, a, b, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b;
        if(a <= 3*b && b <= 3*a)
            cout << (a + b)/4 << '\n';
        else if(a > 3*b)
            cout << b << '\n';
        else if(b > 3*a)
            cout << a << '\n';
    }
    return 0;
}
