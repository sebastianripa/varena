#include <iostream>

using namespace std;

struct nume
{
    string s;
};

nume v[101];
float vt[10];

int main()
{
    int c, tt, tp, n, k, i, im, j;
    float t, tm = 1000000, s = 0, sp = 0, r, m = 0;
    cin >> c >> tt >> tp >> n >> k;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> v[i].s;
            for(j = 1; j <= tt; j++)
            {
                cin >> t;
                if(t < tm)
                {
                    tm = t;
                    im = i;
                }
            }
        }
        cout << v[im].s << '\n';
    }
    else if(c == 2)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> v[i].s;
            for(j = 1; j <= tt; j++)
            {
                if(j == k)
                    cin >> vt[i];
                else
                    cin >> t;
            }
        }
        for(i = 1; i <= n; i++)
        {
            if(vt[i] < m)
            {
                m = vt[i];
                im = i;
            }
        }
        cout << v[im].s << '\n';
    }
    return 0;
}
