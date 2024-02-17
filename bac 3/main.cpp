#include <iostream>

using namespace std;

int vf[10];

int main()
{
    int n, c, nrp, i, j, nr;
    bool ok = true;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> c;
        vf[c]++;
        if(c%2 == 0)
            nrp++;
    }
    if(nrp <= 1)
    {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= 10; i++)
    {
        if(i%2 == 0 && vf[i] > 1)
            nrp = i;
        if(vf[i]%2 == 1)
        {
            if(n%2 == 1 && ok)
                ok = false;
            else
            {
                cout << -1;
                return 0;
            }
        }
    }
    for(i = 1; i <= vf[nrp]/2; i++)
        cout << nrp;
    for(i = 1; i <= 10; i++)
    {
        if(vf[i]%2 == 0 && i != nrp)
        {
            for(j = 1; j <= vf[i]/2; j++)
                cout << i;
        }
        if(vf[i] == 1)
            nr = i;
    }
    if(n%2 == 1)
        cout << nr;
    for(i = 10; i >= 1; i--)
    {
        if(vf[i]%2 == 0 && i != nrp)
        {
            for(j = 1; j <= vf[i]/2; j++)
                cout << i;
        }
    }
    for(i = 1; i <= vf[nrp]/2; i++)
        cout << nrp;
    return 0;
}
