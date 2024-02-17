#include <iostream>

using namespace std;

int v1[10], v2[10], v3[100001];

int main()
{
    int c, n, x, y, i, j, cx, cy, nrc = 0, k, nr = 1;
    cin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= 10; j++)
            {
                v1[j] = 0;
                v2[j] = 0;
            }
            cin >> x >> y;
            cx = x;
            cy = y;
            while(cx)
            {
                v1[cx%10]++;
                cx /= 10;
            }
            while(cy)
            {
                v2[cy%10]++;
                cy /= 10;
            }
            for(j = 1; j <= 9; j++)
            {
                if(v1[j] > 0 && v2[j] > 0)
                {
                    nrc++;
                    break;
                }
            }
        }
        cout << nrc;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= 10; j++)
            {
                v1[j] = 0;
                v2[j] = 0;
            }
            cin >> x >> y;
            cx = x;
            cy = y;
            while(cx)
            {
                v1[cx%10]++;
                cx /= 10;
            }
            while(cy)
            {
                v2[cy%10]++;
                cy /= 10;
            }
            for(j = 9; j >= 1; j--)
            {
                if(v1[j] > 0 && v2[j] > 0)
                {
                    for(k = 1; k <= min(v1[j], v2[j]); k++)
                    {
                        v3[nr] = j;
                        nr++;
                    }
                }
            }
        }
        for(i = 1; i <= nr; i++)
            cout << v3[i];
    }
    return 0;
}
