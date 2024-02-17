#include <iostream>

using namespace std;

int vf[55];

int main()
{
    int t, n, s, nm = 0, i, j, x, si = 0, sd = 0, nrm = 51, l, cs;
    bool ok = true;
    cin >> t;
    for(l = 1; l <= t; l++)
    {
        for(i = 1; i <= 50; i++)
            vf[i] = 0;
        nm = 0;
        si = 0;
        sd = 0;
        nrm = 51;
        ok = true;
        cin >> n >> s;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            vf[x]++;
            nm = max(x, nm);
            nrm = min(x, nrm);
        }
        for(i = nrm; i <= nm; i++)
        {
            if(vf[i] > 1)
            {
                ok = false;
                break;
            }
            if(vf[i] == 0)
                s -= i;
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }
        for(i = nrm-1; i >= 1; i--)
        {
            s -= i;
            if(s < 0)
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }
        for(i = nm+1; s > 0; i++)
            s -= i;
        if(s < 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}
