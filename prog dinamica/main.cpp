#include <iostream>

using namespace std;

int v[100], w[100], dp[100][100];
string s1, s2;

int knapsack (int n, int c)
{
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            if(j >= w[i-1])
                dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][c];
}

/*int lcs()
{
    int n = s1.length();
    int m = s2.length();
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}*/

int main()
{
    int n, c, i;
    cin >> n >> c;
    for(i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << knapsack(n, c);
    //cin >> s1 >> s2;
    //cout << lcs();
    return 0;
}
