#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bipatrat.in");
ofstream fout ("bipatrat.out");

long long v[1000000];

int main()
{
    long long n, nrc = 0, cn, ognrc, p = 1, nr, k = 1, c;
    while(fin >> n)
    {
        k = 1;
        p = 1;
        nrc = 0;
        if((long long)sqrt(n) != sqrt(n))
            fout << 0 << '\n';
        else
        {
            cn = n;
            while(cn)
            {
                nrc++;
                p *= 10;
                cn /= 10;
            }
            ognrc = nrc;
            cn = n;
            while(nrc+1)
            {
                n = cn;
                if(nrc == ognrc)
                {
                    for(int i = 1; i <= 9; i++)
                    {
                        n = cn;
                        nr = n%p;
                        n /= p;
                        n += i;
                        n = n*p + nr;
                        if((long long)sqrt(n) == sqrt(n))
                        {
                            v[k] = n;
                            k++;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i <= 9; i++)
                    {
                        n = cn;
                        nr = n%p;
                        n /= p;
                        n = n*10+i;
                        n = n*p + nr;
                        if((long long)sqrt(n) == sqrt(n))
                        {
                            v[k] = n;
                            k++;
                        }
                    }
                }
                nrc--;
                p /= 10;
            }
            if(k != 1)
                k--;
            sort(v+1, v+k+1);
            if(v[1] == 0)
                fout << 0;
            for(long long i = 1; i < k; i++)
            {
                if(v[i] == v[i+1])
                    v[i] = 0;
            }
            for(long long i = 1; i <= k; i++)
            {
                if(v[i] != 0)
                    fout << v[i] << ' ';
                v[i] = 0;
            }
            fout << '\n';
        }
    }
    return 0;
}
