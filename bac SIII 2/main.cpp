#include <iostream>

using namespace std;

int a[105][105];

int main()
{
    int n, m, nrma = 0, i, j, mini = INT_MAX;
    cin >> n >> m;
    for(i = 0; i <= m+1; i++)
        a[0][i] = 11;
    for(i = 0; i <= n+1; i++)
        a[i][m+1] = 11;
    for(i = m+1; i >= 0; i--)
        a[n+1][i] = 11;
    for(i = n+1; i >= 1; i--)
        a[i][0] = 11;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            mini = INT_MAX;
            mini = min(a[i-1][j], mini);
            mini = min(a[i][j+1], mini);
            mini = min(a[i+1][j], mini);
            mini = min(a[i][j-1], mini);
            if(mini > a[i][j])
                nrma += (mini - a[i][j]);
        }
    }
    cout << nrma;
    return 0;
}
