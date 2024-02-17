#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c, m, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        m = max(a, max(b, c));
        if(m == a)
        {
            if(a == b + c)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else if(b == m)
        {
            if(a + c == b)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            if(a + b == c)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}
