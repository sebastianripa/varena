#include <fstream>

using namespace std;

ifstream fin("rafturi.in");
ofstream fout("rafturi.out");

int dp[10010], mx[10010];

int main()
{
    int c, n, a, b;
    fin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> a >> b; a--;
        mx[a] = max(mx[a], b);
    }
    for (int i = 0; i <= c; i++)
        dp[i] = 2e9;
    dp[0] = 0;
    for (int i = 1; i <= c; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + mx[i - 1]);
        if (i > 1) dp[i] = min(dp[i], dp[i - 2] + max(mx[i - 1], mx[i - 2]));
        if (i > 2) dp[i] = min(dp[i], dp[i - 3] + max( mx[i - 1], max(mx[i - 2], mx[i - 3])));
    }
    fout << dp[c] << '\n';
}