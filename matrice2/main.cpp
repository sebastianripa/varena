#include <iostream>

using namespace std;

int main()
{
    int n, a[10][10], i, j, s = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                s += a[i][j];
        }
    }
    cout << s;
    return 0;
}
