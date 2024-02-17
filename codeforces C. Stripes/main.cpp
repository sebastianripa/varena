#include <iostream>

using namespace std;

char m[9][9];

int main()
{
    int t, i, j, l, c, n;
    char r = '.';
    cin >> t;
    for(l = 1; l <= t; l++)
    {
        n = 8;
        r = '.';
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cin >> m[i][j];
        }
        for(j = 1; j <= n; j++)
        {
            if(m[1][j] == 'B')
            {
                for(i = 1; i <= n; i++)
                {
                    if(m[i][j] != 'B')
                        break;
                }
                if(i == n + 1)
                {
                    r = 'B';
                    break;
                }
            }
        }
        if(r == '.')
        {
            for(i = 1; i <= n; i++)
            {
                if(m[i][1] == 'R')
                {
                    for(j = 1; j <= n; j++)
                    {
                        if(m[i][j] != 'R')
                            break;
                    }
                    if(j = n + 1)
                    {
                        r = 'R';
                        break;
                    }
                }
            }
        }
        cout << r << '\n';
    }
    return 0;
}
