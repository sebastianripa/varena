#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("apropiate.in");
ofstream fout ("apropiate.out");

bool ePrim(int n)
{
    int d = 2;
    if(n < 2)
    {
        return 0;
    }
    while(d*d <= n)
    {
        if(n%d == 0)
        {
            return 0;
        }
        d++;
    }
    return 1;
}

int main()
{
    int n, i, a, c, m, l, x, y;
    fin >> n >> c;
    for(i = 0; i < n; i++)
    {
        fin >> a;
        m = a;
        l = a;
        if(ePrim(a) == 1)
        {
            fout << a << " ";
        }
        else
        {
            while(ePrim(m) == 0)
            {
                m++;
            }
            while(ePrim(l) == 0)
            {
                l--;
            }
            x = a - l;
            y = m - a;
            if(y < x)
                fout << m << " ";
            else if(x < y)
                fout << l << " ";
            else
            {
                if(c == 1)
                    fout << l << " ";
                else
                    fout << m << " ";
            }
        }
    }
    return 0;
}
