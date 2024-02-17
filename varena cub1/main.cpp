#include <iostream>

using namespace std;

int v[100], vf[11];

int main()
{
    int n, i, j, nrs = 0, nrsm = 0, poz, nrc = 0, nrcm = 0;
    bool unu = false;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        vf[v[i]]++;
    }
    for(i = 1; i <= 11; i++)
    {
        if(vf[i] != 0)
            nrc++;
        if(nrcm < vf[i])
            nrcm = vf[i];
    }
    cout << nrcm;
    for(i = 1; i <= 11; i++)
    {
        if(vf[i] == nrcm)
            cout << i << ' ';
    }
    for(i = 2; i <= n; i++)
    {
        if(v[i-1] == v[i])
        {
            if(nrs == 0)
                nrs += 2;
            else
                nrs++;
        }
        else if(v[i-1] != v[i] && !unu)
            continue;

    }
    return 0;
}
