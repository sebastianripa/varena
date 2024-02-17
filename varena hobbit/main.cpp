#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("hobbit.in");
ofstream fout ("hobbit.out");

int main()
{
    long long a, b, i, p, d, x = 0, y = 0, vx[10] = {0}, vy[10] = {0}, cmmmc = 1;
    fin >> a >> b;
    while(a > 0)
    {
        if(a%2 == 0)
        {
            x++;
        }
        a /= 10;
    }
    while(b > 0)
    {
        if(b%2 == 1)
        {
            y++;
        }
        b /= 10;
    }

    i = 2;
    p = 0;
    while(x > 1)
    {
        if (x%i == 0)
        {
            p++;
            d = i;
            x = x/i;
            if(x == 1)
            {
                vx[d] = p;
            }
        }
        else
        {
            vx[d] = p;
            p = 0;
            i++;
        }
    }
    i = 2;
    p = 0;
    while(y > 1)
    {
        if (y%i == 0)
        {
            p++;
            d = i;
            y = y/i;
            if(y == 1)
            {
                vy[d] = p;
            }
        }
        else
        {
            vy[d] = p;
            p = 0;
            i++;
        }
    }
    for(i = 0; i < 10; i++)
    {
        if(vx[i] > vy[i])
        {
            while(vx[i] > 0)
            {
                cmmmc *= i;
                vx[i]--;
            }
        }
        else
        {
            while(vy[i] > 0)
            {
                cmmmc *= i;
                vy[i]--;
            }
        }
    }
    fout << cmmmc;
    return 0;
}
