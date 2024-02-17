#include <iostream>

using namespace std;

int putere(int n)
{
    int p = 1;
    while(n > 99)
    {
        p *= 10;
        n /= 10;
    }
    return p;
}

int v[100000], vp[100000], vu[100000], vd[100000];

int main()
{
    int c, n, x, ogx, p, nrb = -1, i, j, k = 1;
    cin >> c >> n >> v[1];
    for(i = 2; i <= n; i++)
    {
        cin >> v[i];
        if(c == 1)
        {
            p = putere(v[i]);
            if(v[i]/p != v[i-1]%100 && i != n-1 && i != n)
                nrb++;
            else if(i == n-1)
                nrb += 2;
        }
    }
    for(i = 1; i <= n; i++)
    {
        p = putere(v[i])
        for(j = i+1; j <= n; j++)
        {
            if(v[i]/p == v[j]%100)
            {
                vp[k] = v[i];
            }
        }
    }
    cout << nrb;
    return 0;
}
