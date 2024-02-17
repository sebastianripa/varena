#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n, m, i, j, aux;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        aux = a[i][1];
        for(j = 1; j <= m; j++)
        {
            if(j == m)
                a[i][j] = aux;
            else
                a[i][j] = a[i][j+1];
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
