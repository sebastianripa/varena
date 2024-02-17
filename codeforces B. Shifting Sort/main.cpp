#include <iostream>
#include <algorithm>

using namespace std;

int v[51], vc[51], sec[51], vx[200];

void shift(int l, int r, int d)
{
    int i;
    for(i = l; i <= r-1; i++)
        sec[i] = v[i];
    v[l] = v[r];
    for(i = l; i <= r-1; i++)
        v[i+1] = sec[i];
}

int main()
{
    int t, n, i, j, dif, k = 1, nr = 0;
    bool ok = false;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        ok = false;
        k = 1;
        nr = 0;
        cin >> n;
        for(j = 1; j <= n; j++)
        {
            cin >> v[j];
            vc[j] = v[j];
        }
        sort(vc+1, vc+n+1);
        j = 1;
        while(j != n+1)
        {
            ok = false;
            for(j = 1; j <= n; j++)
            {
                if(v[j] != vc[j] && ok != true)
                {
                    dif = j;
                    ok = true;
                }
                if(ok == true)
                {
                    if(v[j] == vc[dif])
                    {
                        shift(dif, j, j-dif);
                        vx[k] = dif;
                        vx[k+1] = j;
                        vx[k+2] = j-dif;
                        k += 3;
                        nr++;
                        break;
                    }
                }
            }
        }
        cout << nr << '\n';
        for(j = 1; j <= k-1; j += 3)
            cout << vx[j] << ' ' << vx[j+1] << ' ' << vx[j+2] << '\n';
    }
    return 0;
}
