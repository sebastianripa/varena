#include <bits/stdc++.h>

using namespace std;

ifstream fin ("paritar.in");
ofstream fout ("paritar.out");

long long v[250010];

int main()
{
    long long n, i, maxi = 0;
    bool ok = true, c1 = true, c2 = true;
    fin >> n;
    for(i = 1; i <= n*2; i++)
        fin >> v[i];
    if(v[1]%2 != 0)
        ok = false;
    for(i = 1; i <= n*2; i++)
    {
        if(ok == true)
        {
            if(v[i]%2 == 1)
            {
                c1 = false;
                break;
            }
        }
        else
        {
            if(v[i]%2 == 0)
            {
                c1 = false;
                break;
            }
        }
    }
    if(c1 == false)
    {
        for(i = 1; i <= n; i++)
        {
            if(v[i]%2 == 0)
                maxi = max(v[i], maxi);
        }
        if(maxi == 0)
            fout << "NU";
        else
        {
            for(i = n+1; i <= n*2; i++)
            {
                if(v[i]%2 == 1)
                {
                    if(maxi > v[i])
                        c2 = false;
                }
            }
            if(c2 == false)
            {
                maxi = 0;
                c2 = true;
                for(i = 1; i <= n; i++)
                {
                    if(v[i]%2 == 1)
                        maxi = max(v[i], maxi);
                }
                if(maxi == 0)
                    fout << "NU";
                else
                {
                        for(i = n+1; i <= n*2; i++)
                    {
                        if(v[i]%2 == 0)
                        {
                            if(maxi > v[i])
                                c2 = false;
                        }
                    }
                    if(c2)
                        fout << "DA";
                    else
                        fout << "NU";
                }
            }
            else
                fout << "DA";
        }
    }
    else
        fout << "DA";
    return 0;
}
