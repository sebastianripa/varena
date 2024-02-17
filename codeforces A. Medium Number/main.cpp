#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        if(a != max(a, max(b, c)) && a != min(a, min(b, c)))
            cout << a << '\n';
        if(b != max(a, max(b, c)) && b != min(a, min(b, c)))
            cout << b << '\n';
        if(c != max(a, max(b, c)) && c != min(a, min(b, c)))
            cout << c << '\n';
    }
    return 0;
}
