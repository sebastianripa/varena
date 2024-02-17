#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, nrbu = 0, nrbc = 0, nrbd = 0, nrbv = 0, x, i, p, c1, c2;
    bool u = false, c = false, d = false;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        u = false;
        c = false;
        d = false;
        cin >> x;
        p = x;
        c1 = x%10;
        c2 = x%100/10;
        while(c2 < c1)
        {
            x /= 10;
            c1 = c2;
            c2 = x%100/10;
        }
        if(c1 == x && c2 == 0)
        {
            nrbu++;
            u = true;
        }
        if(p == x)
        {
            while(c2 > c1)
            {
                x /= 10;
                c1 = c2;
                c2 = x%100/10;
            }
            if(c1 == x && c2 == 0)
            {
                nrbc++;
                c = true;
            }
            c1 = x%10;
            c2 = x%100/10;
            while(c2 < c1)
            {
                x /= 10;
                c1 = c2;
                c2 = x%100/10;
            }
            if(x == 0 && !c)
            {
                nrbd++;
                d = true;
            }
        }
        c1 = x%10;
        c2 = x%100/10;
        while(c2 > c1)
        {
            x /= 10;
            c1 = c2;
            c2 = x%100/10;
        }
        if(x == c1 && c2 == 0 && !u && !c && !d)
            nrbv++;

    }
    cout << nrbu << '\n' << nrbc << '\n' << nrbd << '\n' << nrbv;
    return 0;
}
