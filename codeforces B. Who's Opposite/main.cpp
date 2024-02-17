#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, a, b, c, dist, nro, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> a >> b >> c;
        if(a >= b)
            dist = a - b;
        else
            dist = b - a;
        nro = dist*2;
        if(c > nro || b > nro || a > nro)
            cout << -1 << '\n';
        else
        {
            if(c > dist)
            {
                if(c - dist == a || c - dist == b)
                    cout << -1 << '\n';
                else
                    cout << c - dist << '\n';
            }
            else
            {
                if(c + dist == a || c + dist == b)
                    cout << -1 << '\n';
                else
                    cout << c + dist << '\n';
            }
        }
    }
    return 0;
}
