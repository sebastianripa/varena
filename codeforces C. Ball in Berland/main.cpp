#include <iostream>

using namespace std;

int vb[200001], vf[200001];

int main()
{
    int t, a, b, k, j, i, l, nrp = 0;
    cin >> t;
    for(l = 1; l <= t; l++)
    {
        cin >> a >> b >> k;
        nrp = 0;
        for(i = 1; i <= k; i++)
            cin >> vb[i];
        for(i = 1; i <= k; i++)
            cin >> vf[i];
        for(i = 1; i <= k-1; i++)
        {
            for(j = i+1; j <= k; j++)
            {
                if(vb[i] != vb[j] && vf[i] != vf[j])
                    nrp++;
            }
        }
        cout << nrp << '\n';
    }
    return 0;
}
