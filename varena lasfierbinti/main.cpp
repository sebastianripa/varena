#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lasfierbinti.in");
ofstream fout ("lasfierbinti.out");

int prim(int n)
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

int main()
{
    long long cerinta, p, c, f, i, pd, r, cc, cf, com, n, x, j;
    bool ok = false;
    fin >> cerinta >> p;
    if(cerinta == 1)
    {
        fin >> c >> f;
        fout << p - p%c + (p - p%f);
    }
    else if(cerinta == 2)
    {
        fin >> c >> f;
        cc = c;
        cf = f;
        pd = c*f;
        r = c%f;
        while(r)
        {
            cc = cf;
            cf = r;
            r = cc%cf;
        }
        com = pd/cf;
        fout << p/com;
    }
    else if(cerinta == 3)
    {
        fin >> c;
        c++;
        for(i = c; i <= p; i++)
        {
            if(prim(i))
            {
                fout << i;
                break;
            }
        }
        if(i == p+1)
            fout << 0;
    }
    else
    {
        fin >> c >> n;
        for(i = 1; i <= n; i++)
        {
            ok = 0;
            fin >> x;
            if(c*c < p)
            {
                if(x < c)
                {
                    ok = 1;
                    fout << 0 << ' ';
                }
                else
                {
                    for(j = 2; j < c; j++)
                    {
                        if(x%j == 0)
                        {
                            ok = 1;
                            fout << 0 << ' ';
                            break;
                        }
                    }
                }
                if(ok == 0)
                    fout << 1 << ' ';
            }
            else
            {
                if(prim(x) && x > c)
                    fout << 1 << ' ';
                else
                    fout << 0 << ' ';
            }

        }
    }
    return 0;
}
