#include <iostream>

using namespace std;

int vp[10001];
char v[10001];

int main()
{
    int n, np, p, i, cont = 0, j;
    char c;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cin >> np;

    for(i = 1; i <= np; i++)
    {
        p = v[i];
        cin >> vp[p];
    }
    return 0;
}
