#include <bits/stdc++.h>

using namespace std;

ifstream fin ("paralele.in");
ofstream fout ("paralele.out");

long long a[1000][40005];
long long vr[1000], vc[40005], sr[1000], sc[40005];

int main()
{
    long long cer, n, m, i, j, x, cnt = 1, r = 0, c;
    bool ok = false;
    fin >> cer >> n >> m;
    if(cer == 1)
    {
        for(i = 1; i <= n; i++)
        {
            cnt = 1;
            for(j = 1; j <= m; j++)
            {
                fin >> a[i][j];
                x = a[i][j];
                if(x == 1)
                {
                    if(!ok)
                        ok = true;
                    else
                        cnt++;
                }
                else
                {
                    if(ok && cnt != 1)
                        vr[i] += (cnt - 1)*cnt/2;
                    ok = false;
                    cnt = 1;
                }
            }
            if(ok)
                vr[i] += (cnt - 1)*cnt/2;
            ok = false;
            cnt = 1;
            sr[i] = sr[i - 1] + vr[i];
        }
        for(i = 1; i <= n - 1; i++)
            r += vr[i]*(sr[n] - sr[i]);
        fout << r;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
                fin >> a[i][j];
        }
        for(j = 1; j <= m; j++)
        {
            for(i = 1; i <= n; i++)
            {
                x = a[i][j];
                if(x == 1)
                {
                    if(!ok)
                        ok = true;
                    else
                        cnt++;
                }
                else
                {
                    if(ok && cnt != 1)
                        vc[j] += (cnt - 1)*cnt/2;
                    ok = false;
                    cnt = 1;
                }
            }
            if(ok && cnt != 1)
                vc[j] += (cnt - 1)*cnt/2;
            ok = false;
            cnt = 1;
            sc[j] = sc[j - 1] + vc[j];
        }
        for(i = 1; i <= m - 1; i++)
            c += vc[i]*(sc[n] - sc[i]);
        fout << c;
    }
    return 0;
}
