#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pacman_xi.in");
ofstream fout ("pacman_xi.out");

long long a[41][41];

int main()
{
    long long n, m;
    fin >> n >> m;
    a[1][2] = 1;
    a[2][2] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 3; j <= m; j++) {
            if(i != 2 || j != 2)
                a[i][j] = a[i][j-1] + a[i-1][j-1];
        }
    }
    fout << a[n][m];
    return 0;
}
