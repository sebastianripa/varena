#include <iostream>

using namespace std;

char v[500001];

int main()
{
    int n, i, l = 1, r = 3, nrg = 0, nrh = 0, ans = 0;
    cin >> n;
    cin.get();
    for(i = 1; i <= n; i++)
        cin.get(v[i]);
    for(i = 1; i <= 3; i++)
    {
        if(v[i] == 'G')
            nrg++;
        else
            nrh++;
    }
    while(r <= n)
    {
        while((nrg == 1 || nrh == 1) && r <= n)
        {
            if(nrg == 1 || nrh == 1)
                ans++;
            r++;
            if(r <= n)
            {
                if(v[r] == 'G')
                    nrg++;
                else
                    nrh++;
            }
        }
        while(nrg != 1 && nrh != 1 && r-l+1 > 3)
        {
            if(v[l] == 'G')
                nrg--;
            else
                nrh--;
            l++;
        }
        while((nrg < 1 || nrh < 1) && r <= n)
        {
            r++;
            if(r <= n)
            {
                if(v[r] == 'G')
                    nrg++;
                else
                    nrh++;
            }
        }
    }
    cout << ans;
    return 0;
}
