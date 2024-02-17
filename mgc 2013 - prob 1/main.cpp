#include <iostream>

using namespace std;

pair <int, int> v[500000];

int main()
{
    int n, m, q, i, j, k, t, s, c;
    cin >> n >> m;
    for(i = 1; i <= m; i++)
        cin >> v[i].first >> v[i].second;
    cin >> q;
    for(k = 1; k <= q; k++)
    {
        cin >> c >> s;
        if(c == 1)
        {
            v[s].first = 0;
            v[s].second = 0;
        }
        else
        {
            t = s;
            i = 1;
            while(t != 1 && i < m+1)
            {
                for(i = 1; i <= m; i++)
                {
                    if(t == v[i].second)
                    {
                        t = v[i].first;
                        break;
                    }
                }
            }
            if(t == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}
