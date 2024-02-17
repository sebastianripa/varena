#include <iostream>

using namespace std;

int v[55];

int main()
{
    int t, n, s, i, m = -1, e, me = 0;
    cin >> t;
    while(t--)
    {
        m = -1;
        me = 0;
        cin >> n >> s;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = 1; i <= n; i++, s--)
        {
            cin >> e;
            me = max(me, e);
            if(v[i] <= s && me == e)
                m = i;
        }
        cout << m << '\n';
    }
    return 0;
}
