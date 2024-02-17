#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("sir.in");
ofstream fout ("sir.out");

int v[100001];

int main()
{
    int c, n, x, xm = 0, i, p, p1 = 0, p2 = 0, s = 0;
    bool m1 = false;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(xm < x)
            {
                xm = x;
                p = i;
            }
            else if(xm == x)
                p = i;
        }
        fout << p;
    }
    else if(c == 2)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(xm < x)
            {
                if(xm != 0)
                    fout << p << " ";
                xm = x;
                p = i;
            }
        }
        fout << p;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(xm < x)
            {
                xm = x;
                p = i;
            }
            v[i] = x;
        }
        for(i = 1; i <= n; i++)
        {
            if(v[i] == xm)
            {
                if(m1 == false)
                {
                    p1 = i;
                    m1 = true;
                }
                else
                    p2 = i;
            }
        }
        for(i = p1; i <= p2; i++)
            s += xm - v[i];
        fout << s;
    }
    return 0;
}
