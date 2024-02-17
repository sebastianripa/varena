#include <iostream>
#define MAXN 100000
#define LOGMAXN 17

using namespace std;

int a[MAXN][LOGMAXN];
int v[MAXN];

void preProcess(int n) {
    for(int i = 0; i < n; i++)
        a[i][0] = i;
    for(int j = 1; 1 << j <= n; j++) {
        for(int i = 0; i + (1 << j) - 1 < n; i++) {
            if(v[a[i][j-1]] < v[a[i+(1<<(j-1))][j-1]])
                a[i][j] = v[a[i][j-1]];
            else
                a[i][j] = v[a[i+(1<<(j-1))][j-1]];
        }
    }
}

int log(int n) {
    int i;
    for(i = 1; 1 << i < n; i++)
        continue;
    return i;
}


int main()
{
    int n, m, l, r;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    preProcess(n);
    for(int i = 1; i <= m; i++) {
        cin >> l >> r;
        int k = log(r - l + 1);
        if(v[a[l][k]] <= v[a[r-(1<<k)+1][k]])
            cout << v[a[l][k]] << '\n';
        else
            cout << v[a[r-(1<<k)+1][k]] << '\n';
    }
    return 0;
}
