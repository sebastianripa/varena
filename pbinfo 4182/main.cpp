#include <iostream>

using namespace std;

int n;

void secventa()
{
    int m = 0, p = 1;
    while(n)
    {
        if(n%100 == 22)
            n -= 2;
        m = m + n%10*p;
        n /= 10;
        p *= 10;
    }
    n = m;
    return;
}

int main()
{
    cin >> n;
    secventa();
    return 0;
}
