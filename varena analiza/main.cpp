#include <bits/stdc++.h>

using namespace std;

ifstream fin ("analiza.in");
ofstream fout ("analiza.out");

int vf[1000005];

bool isPalindrom(int n)
{
    int inv = 0, cn;
    cn = n;
    while(n)
    {
        inv = inv*10 + n%10;
        n /= 10;
    }
    if(inv != cn)
        return false;
    return true;
}

int main()
{
    int c, n, x, sm = 0, s = 0, i, m = 0, m2 = 0, xm = 0;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(isPalindrom(x))
                s++;
            else
            {
                if(sm < s)
                    sm = s;
                s = 0;
            }
        }
        if(sm < s)
            sm = s;
        fout << sm;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            vf[x]++;
            if(m < vf[x])
            {
                xm = x;
                m = vf[x];
            }
            else if(xm == x)
                m++;
        }
        for(i = 1; i <= 1000000; i++)
        {
            if(m2 < vf[i] && vf[i] != m)
                m2 = vf[i];
        }
        fout << m2;
    }
    return 0;
}
