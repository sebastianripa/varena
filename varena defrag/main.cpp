#include <bits/stdc++.h>
#define cin fin
#define cout fout
#define f first
#define s second

using namespace std;

ifstream fin ("defrag.in");
ofstream fout ("defrag.out");

int m[101][721];
int vf[101], v[101];

int main()
{
    int cer, n, m1, nr, i, j, r, c, ans = 0, l = 0, k;
    bool ok = false;
    cin >> cer >> n >> m1 >> nr;
    for(i = 1; i <= nr; i++)
    {
        cin >> r >> c;
        m[r][c] = 1;
        vf[r] = 1;
    }
    if(cer == 1)
    {
        for(i = 1; i <= n; i++)
        {
            if(vf[i] == 0)
                ans++;
        }
        cout << ans;
    }
    else
    {
        /*for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m1; j++)
            {
                if(m[i][j-1] == m[i][j] && m[i][j] == 1)
                    l++;
                else if(v[i].f < l || (v[i].f == l && ok))
                {
                    v[i].f = l;
                    v[i].s = j;
                    l = 0;
                    if(ok)
                        ok = false;
                    if(j == 1)
                        ok = true;
                }
            }
            if(v[i].f < l)
            {
                v[i].f = l;
                v[i].s = j - 1;
                l = 0;
            }
        }
        for(k = 1; k <= n; k++)
        {
            for(i = v[i].s-v[i].f+1, j = v[i].s+1; m[k][i] == 1 || m[k][j] == 1; i--, j++)
                continue;
            if(v[i].s - i - v[i].f <= j - v[i].s)
            {

            }
        }*/
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m1; j++)
                v[i] += m[i][j];
        }

        for(k = 1; k <= n; k++)
        {
            int nru = 0, mx = 0;
            for(i = 1; i <= v[k]; i++)
            {
                m[k][m1+i] = m[k][i];
                if(m[k][i] == 1)
                    nru++;
            }
            mx = max(nru, mx);
            for(i = v[k]+1; i <= m1 + v[k]; i++)
            {
                nru += m[k][i] - m[k][i-v[k]];
                mx = max(nru, mx);
            }
            cout << v[k] - mx << ' ';
        }
    }
    return 0;
}
