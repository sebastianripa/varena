#include <iostream>

using namespace std;

int main()
{
    int k, n, a, b, j2, p, nrc = 0, ca, cnrc, nrns = 0, k2 = 0, j1 = 9, cb, nrc2, i;
    cin >> p >> k >> n >> a >> b;
    if(p == 1)
    {
        j2 = 9;
        while(k)
        {
            cout << j2;
            j2--;
            k--;
        }
    }
    else if(p == 2)
    {
        while(n%100/10 == n%10-1)
        {
            j2 = j2*10+n%10;
            n /= 10;
        }
        j2 = j2*10+n%10;
        n /= 100;
        while(j2)
        {
            n = n*10+j2%10;
            j2 /= 10;
        }
        cout << n;
    }
    else
    {
        ca = a;
        while(ca)
        {
            nrc++;
            ca /= 10;
        }
        j2 = 1;
        cnrc = nrc;
        k = 0;
        while(cnrc)
        {
            k = k*10+j2;
            k2 = k2*10+j1;
            j1--;
            j2++;
        }
        if(k >= a)
            nrns += 2;
        else if(k2 >= a)
            nrns++;
        cb = b;
        nrc2 = 0;
        while(cb)
        {
            nrc2++;
            cb /= 10;
        }
        nrc2--;
        nrc++;
        for(i = nrc; i <= nrc2; i++)
            nrns += 2;
        nrc2++;
        j1 = 9;
        j2 = 1;
        k = 0;
        k2 = 0;
        while(nrc2)
        {
            k = k*10+j2;
            k2 = k2*10+j1;
            j1--;
            j2++;
        }
        if(a <= k)
            nrns += 2;
        else if(a <= k2)
            nrns++;
        cout << nrns;
    }
    return 0;
}
