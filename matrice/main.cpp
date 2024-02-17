#include <iostream>

using namespace std;

int main()
{
    int a[10][10], i, j, n;
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)\
            cout << a[i][j] << " ";
            cout << '\n';
    }
    return 0;
}
