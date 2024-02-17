#include <iostream>

using namespace std;

int v[100005], c[100005];

int main()
{
    int n, a, i, j, jum, m = 0;
    cin >> n >> a;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++)
    {
        jum = v[i]/2;
        for(j = 1; j <= n; j++)
            c[j] = v[j]/jum;

    }
    return 0;
}
