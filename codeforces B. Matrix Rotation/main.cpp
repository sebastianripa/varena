#include <iostream>

using namespace std;

int main()
{
    int t, n, a, b, c, d, i, j, mx = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        mx = 0;
        cin >> a >> b >> c >> d;
        mx = max(a, max(b, max(c, d)));
        if(mx == a)
        {
            if(d < b && d < c)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else if(mx == b)
        {
            if(c < a && c < d)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else if(mx == c)
        {
            if(b < a && b < d)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            if(a < b && a < c)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}
