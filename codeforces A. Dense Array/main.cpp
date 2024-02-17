#include <iostream>

using namespace std;

int main()
{
    int t, n, a, b, nrna = 0, nr, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n >> a;
        nrna = 0;
        for(i = 1; i < n; i++)
        {
            cin >> b;
            if(min(a, b)*2 < max(a, b))
            {
                nr = min(a, b);
                while(nr*2 < max(a, b))
                {
                    nr *= 2;
                    nrna++;
                }
            }
            a = b;
        }
        cout << nrna << '\n';
    }
    return 0;
}
