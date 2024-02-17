#include <bits/stdc++.h>

using namespace std;

ifstream fin ("fill.in");
ofstream fout ("fill.out");


bool a[105][105];

void fil(int i, int j)
{
    a[i][j] = 0;
    if(a[i-1][j] == 1)
        fil(i-1, j);
    if(a[i][j-1] == 1)
        fil(i, j-1);
    if(a[i+1][j] == 1)
        fil(i+1, j);
    if(a[i][j+1] == 1)
        fil(i, j+1);
}

int main()
{
    int n, m, ans = 0;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            fin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 1)
            {
                ans++;
                fil(i, j);
            }
        }
    }
    fout << ans;
    return 0;
}
