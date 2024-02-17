#include <iostream>

using namespace std;

int v[200001], v2[200001];

int main()
{
    int n, m, s, d, x, i, j;
    cin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        cin >> s >> d >> x;
        v2[s] += x;
        v2[d+1] -= x;
    }
    v[1] = v2[1];
    for(i = 2; i <= n; i++)
        v[i] = v[i-1] + v2[i];
    for(i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}
