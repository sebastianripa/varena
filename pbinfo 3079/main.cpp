#include <iostream>

using namespace std;

int main()
{
    int a, b, c = 0, ca, p = 1;
    cin >> a >> b;
    ca = a;
    while(a)
    {
        p *= 10;
        a /= 10;
    }
    p /= 10;
    a = ca;
    while(p)
    {
        c = c*10 + ((a/p%10 + b/p%10)/2);
        p /= 10;
    }
    cout << c;
    return 0;
}
