#include <iostream>

using namespace std;

bool isPrime(long long n)
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

long long ans(long long n)
{
    long long nrfp = 1, f = 3, m = n;
    while(n%2 == 0)
        n /= 2;
    if(n != m)
        nrfp *= 2;
    while(n > 1)
    {
        m = n;
        if(isPrime(n))
        {
            nrfp *= n;
            n /= n;
            continue;
        }
        while(n%f == 0)
            n /= f;
        if(n != m)
            nrfp *= f;
        f += 2;
    }
    return nrfp;
}

int main()
{
    long long n;
    cin >> n;
    cout << ans(n);
    return 0;
}
