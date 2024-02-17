#include <iostream>

using namespace std;

int a[30][30];

int main()
{
    int i, k, n = 22, val = 0;
    for(k = 1; k <= (n+1)/2; k++)
    {
        for(i = k; i <= n-k; i++)
        {
            val++;
            a[k][i] = val;
        }
        for(i = k; i <= n-k; i++)
        {
            val++;
            a[k][n-k+1] = val;
        }
        for(i = n-k+1; i >= k; i--)
        {
            val++;
            a[n-k+1][i] = val;
        }
        for(i = n-k; i >= k+1; i--)
        {
            val++;
            a[k][i] = val;
        }
    }
    cout << a[18][18];
    return 0;
}
