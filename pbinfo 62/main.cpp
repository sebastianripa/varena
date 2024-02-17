#include <iostream>

using namespace std;

bool prim(long long n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long n, f = 2, e = 0;
    cin >> n;
    while(n > 1)
    {
        e = 0;
        while(n%f == 0)
        {
            e++;
            n /= f;
        }
        if(e > 0)
            cout << f << ' ' << e << '\n';
        if(prim(n))
        {
            cout << n << ' ' << 1;
            n /= n;
        }
        f++;
    }
    return 0;
}
