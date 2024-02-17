#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n, i, j, m = 1, cnt = 0, m1, l = 2;
    cin >> n;
    if(n%2 == 1)
    {
        while(m <= n)
        {
            if(m == 1)
            {
                a[n/2+1][n/2+1] = 1;
                m += 2;
            }
            else
            {
                i = n/2 + cnt;
                j = n/2 + cnt;
                m1 = m;
                while(m1)
                {
                    a[i][j] = l;
                    j++;
                    m1--;
                }
                m1 = m;
                j--;
                while(m1)
                {
                    a[i][j] = l;
                    i++;
                    m1--;
                }
                m1 = m;
                i--;
                while(m1)
                {
                    a[i][j] = l;
                    j--;
                    m1--;
                }
                m1 = m;
                j++;
                while(m1)
                {
                    a[i][j] = l;
                    i--;
                    m1--;
                }
                l++;
                cnt--;
                m += 2;
            }
        }
    }
    else
    {
        cnt = -1;
        m = 2;
        while(m <= n)
        {
            if(m == 2)
            {
                a[n/2] [n/2] = 1;
                a[n/2][n/2+1] = 1;
                a[n/2+1][n/2+1] = 1;
                a[n/2+1][n/2] = 1;
                m += 2;
            }
            else
            {
                i = n/2 + cnt;
                j = n/2 + cnt;
                m1 = m;
                while(m1)
                {
                    a[i][j] = l;
                    j++;
                    m1--;
                }
                m1 = m;
                j--;
                while(m1)
                {
                    a[i][j] = l;
                    i++;
                    m1--;
                }
                m1 = m;
                i--;
                while(m1)
                {
                    a[i][j] = l;
                    j--;
                    m1--;
                }
                m1 = m;
                j++;
                while(m1)
                {
                    a[i][j] = l;
                    i--;
                    m1--;
                }
                l++;
                cnt--;
                m += 2;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << a[i][j];
        cout << '\n';
    }
    return 0;
}
