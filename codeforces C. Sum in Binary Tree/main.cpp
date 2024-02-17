#include <iostream>

using namespace std;

int sum(unsigned long long n, unsigned long long r, unsigned long long st)
{
    unsigned long long ina = 0;
    if(n%2 == 0)
        ina = (n - st + 1)/2;
    else
        ina = (n - st)/2;
    if(r > 3)
        return n + sum(ina + st/2, r-1, st/2);
    else if(r == 3)
    {
        if(n%4 <= 1)
            return n + 3;
        else
            return n + 4;
    }
    else if(r == 2)
        return n + 1;
    else
        return 1;
}

int main()
{
    unsigned long long t, n, i, r = 1;
    cin >> t;
    while(t--)
    {
        r = 1;
        cin >> n;
        for(i = 2; i <= n; i *= 2)
            r++;
        cout << sum(n, r, i/2) << '\n';
    }
    return 0;
}
