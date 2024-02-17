#include <bits/stdc++.h>

using namespace std;

ifstream fin ("patrate1.in");
ofstream fout ("patrate1.out");

int S[205][205];
char m[205][205];

void sumepartiale(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (m[i][j] - 48);
    }
}

int main()
{
    int n, i, j, ans = 0, is, js, s, l = 2;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin >> m[i][j];
    }
    sumepartiale(n);
    ans += S[n][n];
    while(l <= n)
    {
        for(i = l; i <= n; i++)
        {
            for(j = l; j <= n; j++)
            {
                is = i - l + 1;
                js = j - l + 1;
                s = S[i][j] - S[is - 1][j] - S[i][js - 1] + S[is - 1][js - 1];
                if(s == l*l)
                    ans++;
            }
        }
        l++;
    }
    fout << ans;
    return 0;
}
