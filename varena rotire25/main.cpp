#include <bits/stdc++.h>

using namespace std;

ifstream fin ("rotire25.in");
ofstream fout ("rotire25.out");

long long ogl(long long n)
{
    int inv = 0;
    while(n)
    {
        if(n%10 != 0)
            inv = inv*10 + n%10;
        n /= 10;
    }
    return inv;
}

int main()
{
    long long c, x, k, i, p = 1, uc;
    fin >> c >> x >> k;
    if(c == 1)
    {
        uc = x%10;
        if(uc == 0)
            p = 0;
        else if(uc == 1)
            p = 1;
        else if(uc == 2)
        {
            if(k%4 == 1)
                p = 2;
            else if(k%4 == 2)
                p = 4;
            else if(k%4 == 3)
                p = 8;
            else if(k%4 == 0)
                p = 6;
        }
        else if(uc == 3)
        {
            if(k%4 == 1)
                p = 3;
            else if(k%4 == 2)
                p = 9;
            else if(k%4 == 3)
                p = 7;
            else if(k%4 == 0)
                p = 1;
        }
        else if(uc == 4)
        {
            if(k%2 == 1)
                p = 4;
            else
                p = 6;
        }
        else if(uc == 5)
            p = 5;
        else if(uc == 6)
            p = 6;
        else if(uc == 7)
        {
            if(k%4 == 1)
                p = 7;
            else if(k%4 == 2)
                p = 9;
            else if(k%4 == 3)
                p = 3;
            else if(k%4 == 0)
                p = 1;
        }
        else if(uc == 8)
        {
            if(k%2 == 1)
                p = 8;
            else if(k%2 == 0)
                p = 6;
        }
        else if(uc == 9)
        {
            if(k%2 == 1)
                p = 9;
            else if(k%2 == 0)
                p = 1;
        }
        while(x > 9)
            x /= 10;
        fout << p*x;
    }
    else
    {
        uc = k;
        k %= 4;
        if(k == 0)
            k = 4;
        if(uc <= 2)
        {
            for(i = 1; i <= k; i++)
            {
                if(i%2 == 1)
                    x *= 5;
                else
                    x *= 2;
                x = ogl(x);
            }
        }
        else
        {
            for(i = 1; i <= k+2; i++)
            {
                if(i%2 == 1)
                    x *= 5;
                else
                    x *= 2;
                x = ogl(x);
            }
        }
        fout << x;
    }
    return 0;
}
