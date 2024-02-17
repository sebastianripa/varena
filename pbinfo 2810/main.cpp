#include <iostream>

using namespace std;

float m[51][51], v[51];

int main()
{
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i <= n/2)
            {
                cin >> m[i][j];
                v[j] += m[i][j];
            }
            else
            {
                cin >> m[i+1][j];
                v[j] += m[i+1][j];
            }
        }
    }
    for(i = 1; i <= n; i++)
        m[n/2+1][i] = v[i]/n;
    for(i = 1; i <= n+1; i++)
    {
        for(j = 1; j <= n; j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
