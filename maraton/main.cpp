#include <iostream>

using namespace std;

char a[1005][1005];
int n, m, k;

bool verifR (int r, int c)
{
    int i, j;
    char cul = a[r][c];
    for(i = r-1; i >= r-2*k; i--)
    {
        if(a[i][c] != cul)
            return false;
    }
    r = r-2*k;
    for(i = c; i <= c+k; i++)
    {
        if(a[r][i] != cul)
            return false;
    }
    c += k;
    for(i = r; i <= r+k; i++)
    {
        if(a[i][c] != cul)
            return false;
    }
    r += k;
    for(i = c; i >= c-k; i--)
    {
        if(a[r][i] != cul)
            return false;
    }
    c -= k;
    for(i = r, j = c; i <= r+k, j <= c+k; i++, j++)
    {
        if(a[i][j] != cul)
            return false;
    }
    return true;
}

int main()
{
    int i, j, r, c, cnt = 0;
    cin >> n >> m >> k;
    if(n < 2*k+1)
        cout << 0;
    else if(m < k+1)
        cout << 0;
    else
    {
        cin.get();
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
                cin.get(a[i][j]);
            cin.get();
        }
        r = n;
        c = 1;
        while(r-2*k >= 1)
        {
            while(c+k <= m)
            {
                if(verifR(r, c))
                    cnt++;
                c++;
            }
            r--;
        }
        cout << cnt;
    }
    return 0;
}
