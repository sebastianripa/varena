#include <iostream>

using namespace std;

long long v[100005];

int main()
{
    long long t, n, sm = 0, i, j, a, b, r, k;
    cin >> t;
    for(k = 1; k <= t; k++)
    {
        sm = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = n; i >= 1; i--)
        {
            if(v[i] == 1)
            {
                sm = max(sm, i*2);
                break;
            }
            for(j = i - 1; j >= 1; j--)
            {
                a = v[i];
                b = v[j];
                while(b != 0)
                {
                    r = a%b;
                    a = b;
                    b = r;
                }
                if(a == 1)
                {
                    sm = max(sm, i+j);
                    break;
                }
            }
        }
        if(sm == 0)
            cout << -1 << '\n';
        else
            cout << sm << '\n';
    }
    return 0;
}
