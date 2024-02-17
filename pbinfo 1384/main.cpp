#include <iostream>

using namespace std;

int a[201][201], ans[201][201];

int main()
{
    int n, m, b;
    cin >> n >> m >> b;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    ans[1][m] = a[1][m];
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            if(i > 1 && j < m)
                ans[i][j] = min(ans[i-1][j], ans[i][j+1]) + a[i][j];
        }
    }
    cout << b - ans[n][m];
    return 0;
}
