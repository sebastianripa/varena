#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d1, m1, y1, d2, m2, y2, i, j, fdw = 1, nrb, dif, dw, nrw = 0, m;
    char c;
    cin >> d1;
    cin.get(c);
    cin >> m1;
    cin.get(c);
    cin >> y1 >> d2;
    cin.get(c);
    cin >> m2;
    cin.get(c);
    cin >> y2;
    if(y1 < 2100)
    {
        nrb = y1/4 - 475;
        dif = y1 - 1900;
        fdw += ((nrb+dif)%7);
        if(y1%4 == 0)
        {
            if(m > 1)
            {
                if(m1 < 8)
                {
                    m = m1 - 1;
                    if(m%2 == 0)
                    {
                        m /= 2;
                        dw = 30*m + 31*m;
                        if(m != 0)
                            dw -= 1;
                        dw += d1;
                    }
                    else
                    {
                        m /= 2;
                        dw = 31*m + 30*(m - 1);
                        if(m != 1)
                            dw -= 1;
                        dw += d1;
                    }
                    dw = (dw%7 + fdw)%7 + 1;
                }
            }
        }
        cout << dw;
    }
    return 0;
}
