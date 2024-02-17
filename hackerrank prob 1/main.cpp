#include <bits/stdc++.h>

using namespace std;

map <int, map <int, int>> m;

int main()
{
    int n, q, i, k, l, c;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
    {
        cin >> k;
        for(int j = 1; j <= k; j++)
            cin >> m[i][j];
    }
    for(i = 1; i <= q; i++)
    {
        cin >> l >> c;
        cout << m[l + 1][c + 1] << '\n';
    }
    return 0;
}
