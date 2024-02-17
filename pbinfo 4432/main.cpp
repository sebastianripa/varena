#include <bits/sdtc++.h>

using namespace std;

ifstream fin ("struguri.in");
ofstream fout ("struguri.out");

int sp[20005], v[20005];

int main()
{
    int cer, n, i, x, ans = 0, l, r;
    fin >> cer >> n;
    if(cer == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            sp[i] = (sp[i-1] + x)%n;
        }
        for(i = 1; i <= n; i++)
        {
            if(v[sp[i]] == 0 && sp[i] != 0)
                v[sp[i]] = i;
            else
            {
                if(ans < i - v[sp[i]])
                {
                    ans = i - v[sp[i]];
                    l = v[sp[i]] + 1;
                    r = i;
                }
            }
        }
        fout << ans << ' ' << l << ' ' << r;
    }
    return 0;
}
