#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sss.in");
ofstream fout ("sss.out");

long long v[100001];

int main()
{
    long long c, n, i, cv, k = 1, s = 0, ck = 1, ms = 0;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> v[i];
            if(i == 1)
            {
                cv = v[i];
                while(cv)
                {
                    if(cv%10 != 0)
                    {
                        k = cv%10;
                        break;
                    }
                    cv /= 10;
                }
            }
        }
        for(i = n; k != 0; i--)
        {
            s += v[i];
            k--;
        }
        fout << s;
    }
    else
    {
        for(i = 1; i <= n; i++)
            fin >> v[i];
        for(i = n; i >= 1; i--)
        {
            if(k == 0)
            {
                k = ck + 1;
                ck++;
                if(ms < s)
                    ms = s;
                s = 0;
            }
            s += v[i];
            k--;
        }
        if(ms < s)
            ms = s;
        fout << ms;
    }
    return 0;
}
