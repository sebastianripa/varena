#include <iostream>

using namespace std;

int vf[100];

int main()
{
    int t, n, a, b, nr, ans = 0, i;
    char c, ogc;
    cin >> t;
    while(t--)
    {
        for(i = 1; i <= 77; i++)
            vf[i] = 0;
        ans = 0;
        cin >> n;
        cin.get();
        cin.get(ogc);
        a = ogc;
        a -= 96;
        for(i = 2; i <= n; i++)
        {
            cin.get(c);
            b = c;
            b -= 96;
            nr = a*10 + b;
            if(vf[nr] == 0)
            {
                ans++;
                vf[nr] = 1;
            }
            ogc = c;
            a = b;
        }
        cout << ans << '\n';
    }
    return 0;
}
