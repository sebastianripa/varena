#include <iostream>
#include <algorithm>

using namespace std;

int a[100][100], v[101], vp[101];

int main()
{
    int n, m, i, j, s = 0, k;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        s = 0;
        for(j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s += a[i][j];
        }
        v[i] = s;
        vp[i] = v[i];
    }
    sort(v+1, v+n+1);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(vp[j] == v[i])
            {
                for(k = 1; k <= m; k++)
                    cout << a[j][k]<< " ";
                cout << '\n';
            }
        }
    }
    return 0;
}
