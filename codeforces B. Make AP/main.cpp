#include <iostream>

using namespace std;

int a, b, c, t, i, j, ca, cb, cc;
//1 4 7
void rezultat()
{
    cin >> a >> b >> c;
    ca = b - (c - b);
    if(ca >= a && ca%a == 0 && ca != 0)
    {
        cout << "yes" << '\n';
        return;
    }
    cb = a + (c - a)/2;
    if(cb >= b && cb%b == 0 && cb != 0)
    {
        cout << "yes" << '\n';
        return;
    }
    cc = b + (b - a);
    if(cc >= c && cc%c == 0 && cc != 0)
    {
        cout << "yes" << '\n';
        return;
    }
    cout << "no" << '\n';
}

int main()
{

    cin >> t;
    for(j = 1; j <= t; j++)
        rezultat();
    return 0;
}
