#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d, i, j;
    cin >> a >> b >> c >> d;
    if(a%3 != 0)
    {
        a += 3;
        a = a-(a%3);
    }
    a /= 3;
    b /= 3;
    i = b-a+1;
    if(c%3 != 0)
    {
        c += 3;
        c = c-(c%3);
    }
    c /= 3;
    d /= 3;
    j = d-c+1;
    cout << i+j;
    return 0;
}
