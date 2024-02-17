#include <bits/stdc++.h>

using namespace std;

int vf[150];
char v[52];

int main()
{
    int t, n, vr = 0, r = 0, i, j;
    cin >> t;
    cin.get(v[51]);
    for(i = 1; i <= t; i++)
    {
        for(j = 97; j <= 122; j++)
            vf[j] = 0;
        j = 1;
        n = 0;
        r = 0;
        vr = 0;
        while(cin.get(v[j]))
        {
            if(v[j] == '\n')
                break;
            vf[v[j]]++;
            j++;
        }
        for(j = 97; j <= 122; j++)
        {
            if(vf[j] >= 2)
            {
                r++;
                vr++;
            }
            else if(vf[j] == 1)
                n++;
        }
        if(n%2 == 0)
        {
            r += n/2;
            vr += n/2;
        }
        else
        {
            n--;
            r += n/2;
            vr += n/2;
        }
        cout << r << '\n';
    }
    return 0;
}
