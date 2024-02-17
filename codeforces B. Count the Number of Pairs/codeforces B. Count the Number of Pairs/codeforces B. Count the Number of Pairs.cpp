#include <iostream>

using namespace std;

int v[123];

int main()
{
    int t, n, k, i, cnr, nrp = 0, dif = 0;
    char c;
    cin >> t;
    while (t--)
    {
        for (i = 1; i <= 122; i++)
            v[i] = 0;   
        dif = 0;
        nrp = 0;
        cin >> n >> k;
        cin.get();
        for (i = 1; i <= n; i++)
        {
            cin.get(c);
            cnr = c;
            v[cnr]++;
            if (cnr < 97)
                v[cnr - 64]++;
            else
                v[cnr - 96]++;
        }
        for (i = 97; i <= 122; i++)
        {
            nrp += min(v[i], v[i - 32]);
            if(max(v[i], v[i - 32]) - min(v[i], v[i - 32]) > 1)
                dif += (max(v[i], v[i - 32]) - min(v[i], v[i - 32]))/2;
        }
        if (k >= dif)
            nrp += dif;
        else
            nrp += k;
        cout << nrp << '\n';
    }
}