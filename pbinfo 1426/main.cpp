#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pozne.in");
ofstream fout ("pozne.out");

int c;
bool ok = false;

bool isPrime(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int ogl(int n)
{
    int inv = 0;
    ok = false;
    while(n)
    {
        if(n%10 == c)
            ok = true;
        inv = inv*10+n%10;
        n /= 10;
    }
    return inv;
}

int main()
{
    int p, n, s, i, x, cx, gigel = 0, nr = 0;
    fin >> p >> n >> s >> c;
    if(p == 1)
    {
        for(i = 1; i <= n; i++)
        {
            ok = false;
            fin >> x;
            cx = x;
            while(x)
            {
                if(x%10 == c)
                {
                    ok = true;
                    break;
                }
                x /= 10;
            }
            if(ok == true)
                fout << cx << ' ';
        }
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(isPrime(ogl(x)))
            {
                if(ok == true)
                    gigel -= s;
                else
                    gigel += s;
                nr++;
            }
        }
        fout << nr << ' ';
        if(gigel == 0)
            fout << 0;
        else if(gigel < 0)
            fout << -1;
        else
            fout << 1;
    }
    return 0;
}
