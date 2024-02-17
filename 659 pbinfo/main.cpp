#include <iostream>

using namespace std;

int a[100][100], v[100];

int main()
{
    int n, m, i, j, s = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(v[i] < a[i][j])
                v[i] = a[i][j];
        }
    }
    for(i = 1; i <= n; i++)
    {
        s = 0;
        for(j = 1; j <= m; j++)
        {
            if(a[i][j] != v[i])
                s += a[i][j];
            else
                v[i] = -1;
        }
        cout << s << ' ';
    }
    return 0;
}
