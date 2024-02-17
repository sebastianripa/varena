#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cate3cifre.in");
ofstream fout ("cate3cifre.out");

int v[1000005], b[5];

void sumepar(int n)
{
    int cnt = 4, pz = 1, nr = 2;
    while(nr <= n)
    {
        v[nr] = pz;
        nr += cnt;
        cnt += 2;
        pz++;
    }
}

int main()
{
    int c, n, i, j, cnt = 0;
    fin >> c >> n;
    sumepar(n);
    while(cnt != 2)
    {
        cnt = 0;
        if(v[n - 1] != 0)
        {
            cnt++;
            b[cnt] = v[n-1];
        }
        for(i = 2, j = 4; i <= n/2; i += j, j += 2)
        {
            if(n%(i + 1) == 0)
            {
                if(n/i >= v[i])
                    continue;
                cnt++;
                b[cnt] = v[i];
            }
            if(cnt > 2)
                break;
        }
        n--;
    }
    n++;
    if(c == 1)
        fout << n;
    else
    {
        if(b[1] > b[2])
        {
            fout << b[2] << ' ' << n/(b[2]*(b[2] + 1) + 1) << '\n';
            fout << b[1] << ' ' << n/(b[1]*(b[1] + 1) + 1);
        }
        else
        {
            fout << b[1] << ' ' << n/(b[1]*(b[1] + 1) + 1) << '\n';
            fout << b[2] << ' ' << n/(b[2]*(b[2] + 1) + 1);
        }
    }
    return 0;
}
