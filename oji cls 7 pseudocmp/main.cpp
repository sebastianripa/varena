#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pseudocmp.in");
ofstream fout ("pseudocmp.out");

int v[100005], s[100005];

int main()
{
    long long c, n, i, j, cv, nrs = 0, sc = 0;
    bool sol = false;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
        cv = v[i];
        while(cv)
        {
            s[i] += cv%10;
            cv /= 10;
        }
    }
    if(c == 1)
    {
        if(n < 1000)
        {
            for(i = 1; i <= n; i++)
            {
                for(j = i; j <= n; j++)
                {
                    if(v[i] > v[j])
                    {
                        if(s[j] > s[i])
                        {
                            sol = true;
                            fout << v[j] << ' ' << v[i];
                            break;
                        }
                    }
                    else if(v[j] > v[i])
                    {
                        if(s[i] > s[j])
                        {
                            sol = true;
                            fout << v[i] << ' ' << v[j];
                            break;
                        }
                    }
                }
                if(sol == true)
                    break;
            }
        }
        if(sol == false)
            fout << -1;
        if(n > 1000)
        {
            sort(s+1, s+n+1);
            for(i = 1; i <= n; i++)
            {
                sc = 0;
                cv = v[i];
                while(cv)
                {
                    sc += cv%10;
                    cv /= 10;
                }
                for(j = 1; j <= n; j++)
                {
                    if(s[i] == sc)
                    {
                        s[i] = s[i]*10 + i;
                        break;
                    }
                }
            }
            for(i = n; i >= 1; i--)
            {
                for(j = i - 1; j >= 1; j--)
                {
                    if(v[s[i]%10] < v[s[j]%10])
                    {
                        sol = true;
                        fout << v[s[j]%10] << ' ' << v[s[i]%10];
                        break;
                    }
                }
                if(sol == true)
                    break;
            }
            if(sol == false)
                fout << -1;
        }
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                if(v[i] > v[j])
                {
                    if(s[j] > s[i])
                        nrs++;
                }
                else if(v[j] > v[i])
                {
                    if(s[i] > s[j])
                        nrs++;
                }
            }
        }
        fout << nrs;
    }
    return 0;
}
