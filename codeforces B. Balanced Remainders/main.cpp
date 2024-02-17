#include <iostream>

using namespace std;

int v[30001];

int main()
{
    long long t, n, c0, c1, c2, i, j, c, nrm = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        nrm = 0;
        c0 = 0;
        c1 = 0;
        c2 = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i]%3 == 0)
                c0++;
            else if(v[i]%3 == 1)
                c1++;
            else
                c2++;
        }
        c = n/3;
        if(max(c0, max(c1, c2)) == c0)
        {
            while(c0 > c)
            {
                c0--;
                c1++;
                nrm++;
            }
        }
        else if(max(c0, max(c1, c2)) == c1)
        {
            while(c1 > c)
            {
                c1--;
                c2++;
                nrm++;
            }
        }
        else
        {
            while(c2 > c)
            {
                c2--;
                c0++;
                nrm++;
            }
        }
        if(max(c0, max(c1, c2)) == c0)
        {
            while(c0 > c)
            {
                c0--;
                c1++;
                nrm++;
            }
        }
        else if(max(c0, max(c1, c2)) == c1)
        {
            while(c1 > c)
            {
                c1--;
                c2++;
                nrm++;
            }
        }
        else
        {
            while(c2 > c)
            {
                c1--;
                c2++;
                nrm++;
            }
        }
        cout << nrm << '\n';
    }
    return 0;
}
