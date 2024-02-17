#include <iostream>
#include <algorithm>

using namespace std;

int a[9][11];

int main()
{
    int m = 10, n = 8, k=10;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (i%2 == 1)
                a[i][j] = k++;
            else
                a[i][m-j+1] = k++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
