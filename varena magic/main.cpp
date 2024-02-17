#include <iostream>

using namespace std;

int m1[102][102], m2[102][102], ms[5][102];

void solve1(int n)
{
    int i, j, m = 1, cnt = 1, cnt1 = 1, i1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            m1[i][j] = cnt++;
    }
    for(i1 = 1; i1 <= n/2; i1++)
    {
        for(i = 1, j = i1; j >= 1; i++, j--)
            ms[1][m++] = m1[i][j];
    }
    m = 1;
    for(i1 = 1; i1 <= n/2; i1++)
    {
        for(i = 1, j = n - i1 + 1; j <= n; i++, j++)
            ms[2][m++] = m1[i][j];
    }
    m = 1;
    for(i1 = 1; i1 <= n/2; i1++)
    {
        for(i = n - i1 + 1, j = 1; i <= n; i++, j++)
            ms[3][m++] = m1[i][j];
    }
    m = 1;
    for(i1 = 1; i1 <= n/2; i1++)
    {
        for(i = n - i1 + 1, j = n; i <= n; i++, j--)
            ms[4][m++] = m1[i][j];
    }
    cnt = 1;
    for(i = 1, j = n/2+1; i <= n/2+1; i++, j++)
    {
        m2[cnt1][cnt] = m1[i][j];
        cnt+=2;
    }
    cnt1++;
    for(i1 = 1; i1 <= n/2; i1++)
    {
        cnt = 2;
        for(i = i1 + 1, j = n/2 + 2 - i1; cnt < n; i++, j++)
        {
            m2[cnt1][cnt] = m1[i][j];
            cnt += 2;
        }
        cnt1++;
        cnt = 1;
        for(i = i1 + 1, j = n/2 + 1 - i1; cnt <= n; i++, j++)
        {
            m2[cnt1][cnt] = m1[i][j];
            cnt+=2;
        }
        cnt1++;
    }
    cnt1 = 1;
    for(j = n/2 + 2; j <= n; j++)
    {
        cnt = 1;
        for(i = n/2 + 2 - (j - n/2 - 1); cnt <= j - n/2 - 1; i += 2, cnt++)
            m2[i][j] = ms[1][cnt1++];
    }
    cnt1 = 1;
    for(i = n/2 + 2; i <= n; i++)
    {
        cnt = 1;
        for(j = n/2 + 2 - (i - n/2 - 1); cnt <= i - n/2 - 1; j += 2, cnt++)
            m2[i][j] = ms[2][cnt1++];
    }
    cnt1 = 1;
    for(i = n/2; i >= 1; i--)
    {
        cnt = 1;
        for(j = i + 1; cnt <= n/2 - i + 1; j += 2, cnt++)
            m2[i][j] = ms[3][cnt1++];
    }
    cnt1 = 1;
    for(j = n/2; j >= 1; j--)
    {
        cnt = 1;
        for(i = j + 1; cnt <= n/2 - j + 1; i += 2, cnt++)
            m2[i][j] = ms[4][cnt1++];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << m2[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    int n, m, row, col, i, j, i1;
    cin >> n >> m >> row >> col;
    solve1(n);
    return 0;
}
