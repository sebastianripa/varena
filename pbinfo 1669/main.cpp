#include <iostream>

using namespace std;

bool prim(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool palindrom(int n)
{
    int i, j, cn, nrc = 0, p = 1;
    cn = n;
    while(cn)
    {
        nrc++;
        p *= 10;
        cn /= 10;
    }
    p /= 10;
    for(i = 1, j = n; i <= nrc/2 && j >= nrc/2; i++, j--)
    {
        if(n%10 != n/p)
            break;
        p /= 10;
        n /= 10;
    }
    if(i == nrc/2+1)
        return true;
    return false;
}

int main()
{
    int n, x, nrppn = 0, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        if(prim(x) && x%2 == 1)
        {
            if(palindrom(x))
                nrppn++;
        }
    }
    cout << nrppn;
    return 0;
}
