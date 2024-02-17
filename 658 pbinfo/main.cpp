#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n, m, i, j, s;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        s = 0;
        for(j = 1; j <= m; j++)
            s += a[i][j];
        cout << s << ' ';
    }
    return 0;
}
