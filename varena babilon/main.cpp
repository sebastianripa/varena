#include <bits/stdc++.h>

using namespace std;

ifstream fin ("babilon.in");
ofstream fout ("babilon.out");

int main()
{
    long long c, n, x, nrs = 0, i, maxi = 0, a, b, s = 0;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(x == 1)
                nrs++;
            else
            {
                maxi = max(nrs, maxi);
                nrs = 0;
            }
        }
        maxi = max(nrs, maxi);
        fout << maxi;
    }
    else
    {
        fin >> a;
        if(a == 1)
            s++;
        else
            s += 10;
        for(i = 2; i <= n; i++)
        {
            fin >> b;
            if(b > a)
                s *= 60;
            if(b == 1)
                s++;
            else if(b == 2)
                s += 10;
            if(b!=3)
                a=b;
        }
        fout << s;
    }
    return 0;
}
