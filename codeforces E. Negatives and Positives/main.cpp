#include <bits/stdc++.h>

using namespace std;

int v[200005];

int main()
{
    long long n, t, i, j, nrm = 0, s = 0;
    cin >> t;
    while(t--)
    {
        nrm = 0;
        s = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i] < 0)
                nrm++;
        }
        sort(v+1, v+n+1);
        if(nrm%2 == 0)
        {
            for(i = 2; i <= nrm; i += 2)
            {
                v[i-1] = -v[i-1];
                v[i] = -v[i];
            }
        }
        else
        {
            for(i = 2; i <= nrm - 1; i += 2)
            {
                v[i-1] = -v[i-1];
                v[i] = -v[i];
            }
            if(-v[nrm] > v[nrm+1] && nrm+1 <= n)
            {
                v[nrm] = -v[nrm];
                v[nrm+1] = -v[nrm+1];
            }
        }
        for(i = 1; i <= n; i++)
            s += v[i];
        cout << s << '\n';
    }
    return 0;
}
