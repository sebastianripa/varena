#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sumtri.in");
ofstream fout ("sumtri.out");

int a[101][101], s[101][101];

int main()
{
    int n, sm = 0;
    fin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            fin >> a[i][j];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            s[i][j] = max(s[i-1][j], s[i-1][j-1]) + a[i][j];
            sm = max(sm, s[i][j]);
        }
    }
    fout << sm;
    return 0;
}
