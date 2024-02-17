#include <bits/stdc++.h>

using namespace std;

int v[400001];

int main()
{
    int t, n, c = 0, i, j, nri = 0, k, l;
    bool terminate = false;
    cin >> t;
    for(l = 1; l <= t; l++)
    {
        nri = 0;
        c = 0;
        terminate = false;
        cin >> n >> k;
        for(i = 1; i <= k; i++)
            cin >> v[i];
        sort(v+1, v+k+1);
        j = 1;
        for(i = k; i >= 1; i--)
        {
            c += n - v[i];
            v[i] = INT_MAX;
            nri++;
            for(j; j <= k; j++)
            {
                if(c >= v[j])
                    v[j] = -1;
                else if(v[j] == INT_MAX)
                {
                    terminate = true;
                    break;
                }
                else
                    break;
            }
            if(terminate)
                break;
        }
        cout << nri << '\n';
    }
    return 0;
}
