#include <bits/stdc++.h>

using namespace std;

ifstream fin ("intervale2.in");
ofstream fout ("intervale2.out");

int vf[100005], vp[100005], v[100005];

int main()
{
    int n, q, a, b, i, j, cnt = 1, x, ogx, st, fn, ans = 0;
    bool ok1 = false, ok2 = false;
    fin >> n >> x;
    ogx = x;
    vp[1] = 1;
    v[1] = x;
    vf[1]++;
    for(i = 2; i <= n; i++)
    {
        fin >> x;
        if(ogx == x)
            vf[cnt]++;
        else
        {
            vp[++cnt] = i;
            vf[cnt]++;
        }
        v[i] = x;
        ogx = x;
    }
    for(i = 2; i <= cnt; i++)
        vf[i] = vf[i-1] + vf[i];
    fin >> q;
    for(j = 1; j <= q; j++)
    {
        ok1 = false;
        ok2 = false;
        ans = 0;
        st = 0;
        fn = 0;
        fin >> a >> b;
        for(i = 1; i <= cnt; i++)
        {
            if(v[vp[i]] >= a && !ok1)
            {
                st = i;
                ok1 = true;
            }
            if(v[vp[i]] > b)
            {
                fn = i - 1;
                ok2 = true;
                break;
            }
            else if(v[vp[i]] == b)
            {
                fn = i;
                ok2 = true;
                break;
            }
        }
        if(fn == 0 && !ok2 && st != 0)
            fn = cnt;
        ans = vf[fn] - vf[st-1];
        fout << ans << '\n';
    }
    return 0;
}
