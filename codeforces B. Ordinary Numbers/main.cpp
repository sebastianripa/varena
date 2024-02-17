#include <iostream>

using namespace std;

int main()
{
    int t, n, nro = 9, p = 10, i, j, cn, nrcn, pcn, cnrcn;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        nro = 0;
        p = 10;
        cin >> n;
        if(n <= 10)
        {
            if(n == 10)
                cout << n - 1 << '\n';
            else
                cout << n << '\n';
            continue;
        }
        else if(n <= 100)
        {
            if(n == 100 || n == 99)
            {
                cout << 18 << '\n';
                continue;
            }
            if(n/10%10 <= n%10)
                cout << n/10%10+9 << '\n';
            else
                cout << n/10%10-1+9 << '\n';
            continue;
        }
        else
        {
            cn = n;
            while(cn > 9)
            {
                nrcn++;
                cn /= 10;
            }
            pcn = cn;
            cnrcn = nrcn;
            while(cnrcn)
            {
                cn = cn*10 + pcn;
                cnrcn--;
            }
            if(cn > n)
                pcn--;
            cn = 1;
            while(nrcn)
            {
                cn *= 10;
                nrcn--;
            }
            while(cn >= p)
            {
                nro += 9;
                p *= 10;
            }
            nro += pcn;
        }
        cout << nro << '\n';
    }
    return 0;
}
