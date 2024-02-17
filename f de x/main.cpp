#include <iostream>

using namespace std;

long long f(long long x)
{

}

int main()
{
    long long l, r, fdx, m;
    cin >> fdx;
    l = 0;
    r = LLONG_MAX;
    while(l < r)
    {
        m = (l+r)/2;
        if(f(m) < fdx)
            l = m + 1;
        else if(f(m) > fdx)
            r = m - 1;
        else
            break;
    }
    cout << m;
    return 0;
}
