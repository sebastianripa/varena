#include <bits/stdc++.h>

using namespace std;

ifstream fin ("chimie1.in");
ofstream fout ("chimie1.out");

int n, a, b;

bool div(int x)
{
    int d = 2, e = 0;
    while(x)
    {
        e = 0;
        while(d%x == 0)
        {
            d /= x;
            e++;
        }
        if(d != a && d != b)
            return false;
        d++;
    }
    return true;
}

int main()
{
    int i, x, maxi = 0, nrm = 0;
    fin >> n >> a >> b;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(div(x))
        {
            if(maxi < cx)
            {
                maxi = cx;
                nrm = 1;
            }
            else if(maxi == cx)
                nrm++;
        }
    }
    if(maxi == 0)
        fout << "NU EXISTA";
    else
        fout << maxi << ' ' << nrm;
    return 0;
}
