#include <iostream>

using namespace std;

int v[98];

int main()
{
    int t, n, a, i, j, oga;
    char c, ogc;
    bool repetat = false;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        repetat = false;
        for(j = 65; j <= 90; j++)
            v[j] = 0;
        cin >> n >> c;
        for(j = 2; j <= n; j++)
        {
            ogc = c;
            oga = ogc;
            cin >> c;
            a = c;

            if(v[a] == 1)
                repetat = true;
            else if(ogc != c)
                v[oga] = 1;
        }
        if(repetat == false)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
