#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("cladire.in");
ofstream fout ("cladire.out");

int m[1005][1005];

int main()
{
    int n, m1;
    cin >> n >> m1;
    m[1][2] = 1;
    m[2][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m1; j++) {
            if((i != 1 || j != 2) && (i != 2 || j != 1))
                m[i][j] = (m[i-1][j] + m[i][j-1])%9901;
        }
    }
    cout << m[n][m1];
    return 0;
}
