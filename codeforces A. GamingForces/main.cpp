#include <bits/stdc++.h>

using namespace std;

int v[105], vf[105], vnr[105];

int main()
{
    int t, n, i, j, dh = 1, ndh = 1, ans = 0;
    cin >> t;
    while(t--)
    {
        for(i = 1; i <= ndh; i++)
            vf[i] = 0;
        dh = 1;
        ans = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        sort(v+1, v+n+1);
        vf[1] = 1;
        vnr[1] = v[1];
        j = 1;
        for(i = 2; i <= n; i++)
        {
            if(v[i-1] != v[i])
            {
                dh++;
                j++;
                vnr[j] = v[i];
                vf[j]++;
            }
            else
                vf[j]++;
        }
        ndh = j;
        for(i = 1; i <= ndh; i++)
        {
            if(vf[i]%2 == 0)
            {
                if(vf[i]/2*vnr[i] <= vf[i])
                    ans += vf[i]/2*vnr[i];
                else
                    ans += vf[i];
            }
            else
            {
                if(vf[i]/2*vnr[i]+1 <= vf[i])
                    ans += vf[i]/2*vnr[i] + 1;
                else
                    ans += vf[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
