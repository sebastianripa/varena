#include <iostream>

using namespace std;

long long v[12];

int main()
{
    long long t, n, i, m, s;
    cin >> t;
    while(t--)
    {
        v[1] = 200001;
        v[10] = 200001;
        v[11] = 200001;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> m >> s;
            if(s == 1)
                v[1] = min(v[1], m);
            else if(s == 10)
                v[10] = min(v[10], m);
            else if(s == 11)
                v[11] = min(v[11], m);
        }
        if(v[11] > 200000 && (v[1] > 200000 || v[10] > 200000))
            cout << -1 << '\n';
        else
        {
            if(v[1] + v[10] <= v[11])
                cout << v[1] + v[10] << '\n';
            else
                cout << v[11] << '\n';
        }
    }
    return 0;
}
