#include <iostream>

using namespace std;

char a[501][501];

int main()
{
    int t, n, i, j, r1 = 0, c1 = 0, r2 = 0, c2 = 0, k;
    cin >> t;
    for(k = 1; k <= t; k++)
    {
        r1 = 0;
        c1 = 0;
        r2 = 0;
        c2 = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == '*')
                {
                    if(r1 == 0)
                    {
                        r1 = i;
                        c1 = j;
                    }
                    else
                    {
                        r2 = i;
                        c2 = j;
                    }
                }
            }
        }
        if(r1 == r2)
        {
            if(r1 > 1)
            {
                a[r1-1][c1] = '*';
                a[r2-1][c2] = '*';
            }
            else
            {
                a[r1+1][c1] = '*';
                a[r2+1][c2] = '*';
            }
        }
        else if(c1 == c2)
        {
            if(c1 > 1)
            {
                a[r1][c1-1] = '*';
                a[r2][c2-1] = '*';
            }
            else
            {
                a[r1][c1+1] = '*';
                a[r2][c2+1] = '*';
            }
        }
        else
        {
            a[r1][c2] = '*';
            a[r2][c1] = '*';
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cout << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}
