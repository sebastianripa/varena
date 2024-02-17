#include <bits/stdc++.h>

using namespace std;

int vb[200001];

int main()
{
    int t, n, x, i, j = 1, nrh = 0, s = 0, c;
    cin >> t;
    while(t--)
    {

        for(i = 1; vb[i] != 0; i++)
            vb[i] = 0;
        s = 0;
        nrh = 0;
        j = 1;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x == 0)
                nrh++;
            else
                vb[j++] = x;
        }
        j--;
        sort(vb+1, vb+j+1);
        for(i = 1; i <= min(j, nrh); i++)
            s += vb[j-i+1];
        cout << s << '\n';
    }
    return 0;
}
