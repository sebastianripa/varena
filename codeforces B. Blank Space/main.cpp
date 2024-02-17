#include <iostream>

using namespace std;

int main()
{
    int t, n, x, nrz = 0, blm = 0, i;
    bool ok = false;
    cin >> t;
    while(t--)
    {
        blm = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x == 0)
            {
                if(!ok)
                {
                    nrz++;
                    ok = true;

                }
                else
                    nrz++;
            }
            else if(ok)
            {
                blm = max(blm, nrz);
                nrz = 0;
                ok = false;
            }
        }
        blm = max(blm, nrz);
        nrz = 0;
        ok = false;
        cout << blm << '\n';
    }
    return 0;
}
