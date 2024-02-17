#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("vecine.in");
ofstream fout ("vecine.out");

int v[100001];

int caut(int st1, int st2)
{
    int i, n = st2 - st1 - 1, p = 1, nr = 0;
    for(i = 1; i <= n-1; i++)
    {
        if(v[i+st1] != v[i+st2])
            break;
        p *= 10;
    }
    if(i != n)
        return 0;
    if(v[n+st1] != v[n+st2]-1)
        return 0;
    p *= 10;
    for(i = 0; i <= n; i++)
    {
        nr += v[i+st1]*p;
        p /= 10;
    }
    return nr;
}

int main()
{
    int cer, n, i, ans = 0, j, ansp, ans1 = 0;
    cin >> cer >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 2; i <= n; i++)
    {
        if(v[i] == v[i-1]+1)
        {
            ans1++;
            ans = max(v[i], ans);
        }
    }
    if(cer == 1)
        cout << ans1;
    if(cer == 2)
    {
        for(i = 1; i <= n/2; i++)
        {
            for(j = i+1; j <= n/2 + i - 1; j++)
            {
                if(v[i] == v[j] && v[i] != 0)
                {
                    ansp = caut(i, j);
                    ans = max(ansp, ans);
                }
            }
        }
        cout << ans;
    }
    return 0;
}
