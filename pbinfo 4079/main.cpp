#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ceas.in");
ofstream fout ("ceas.out");


int main()
{
    int c, x, n, nr, i, nrc = 0;
    if(c == 1)
    {
        fin >> c >> nr >> n;
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(x == 0 && nr == 0)
                nrc++;
            while(x)
            {
                if(x%10 == nr)
                    nrc++;
                x /= 10;
            }
        }
        fout << nrc;
    }
    else
    {
        fin >> c >> nr >> n;
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            while(x)
            {
                if(x%100 > 9 && x%100 < 13)
                {
                    if(x%100 != x)
                        nrc++;
                    x /= 100;
                }
                else
                {
                    if(x < 10)
                        break;
                    nrc++;
                    x /= 10;
                }
            }
        }
        fout << nrc;
    }
    return 0;
}
