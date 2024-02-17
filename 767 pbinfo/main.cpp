#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n, m, s = 0, i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j]%2 == 0)
                s += a[i][j];
        }
    }
    cout << s;
    return 0;
}
