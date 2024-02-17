#include <iostream>

using namespace std;

int r[4005], u[4001], epr[4001], epu[4001];

int main()
{
    int c, n, m, x, y, i, j, cont1 = 0, cont2 = 0;
    bool real = true, uman = true;
    cin >> c >> n >> m;
    for(i = 1; i <= m; i++)
        cin >> r[i];
    for(i = 1; i <= m; i++)
        cin >> u[i];
    for(i = m+1; i <= m+n; i++)
    {
        cin >> r[i] >> u[i];
        epr[r[i]] = 1;
        epu[u[i]] = 1;
    }
    sort(r+1, r+n+m+1);
    sort(u+1, u+n+m+1);
    for(i = n+m; i > n; i--)
    {
        if(epr[r[i]] == 1)
            cont++;

    }
    if(uman == true)
    {
        cout << n;
        for(i = 1; i <= n; i++)
            cout << 'U';
    }
    return 0;
}
