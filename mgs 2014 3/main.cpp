#include <iostream>

using namespace std;

long long v[200005];

int vrblocks(int n)
{
    int i, nrb = 1;
    for(i = 2; i <= n; i++)
    {
        if(v[i] <= v[i-1])
            nrb++;
    }
    return nrb;
}

int main()
{
    int n, i, x, y, c, aux, q, k, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cin >> q;
    for(i = 1; i <= q; i++)
    {
        cin >> c;
        if(c == 1)
        {
            cin >> x >> y;
            v[x] = y;
            cout << vrblocks(n) << '\n';
        }
        else
        {
            cin >> x;
            for(j = 1; j <= x; j++)
            {
                aux = v[1];
                for(k = 2; k <= n; k++)
                    v[k-1] = v[k];
                v[n] = aux;
            }
            cout << vrblocks(n) << '\n';
        }
    }
    return 0;
}
