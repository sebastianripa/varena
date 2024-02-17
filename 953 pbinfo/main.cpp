#include <iostream>

using namespace std;

int v[100001];

int main()
{
    long long n, k, u = 3, ogu = 1, i, nrd = 0, nrdm = 0, r, aux;
    cin >> n >> k;
    for(i = 1; i <= k; i++)
        cin >> v[i];
    i = 1;
    while(u <= n*(n+1)/2)
    {
        nrd = 0;
        for(; i <= k; i++)
        {
            if(v[i] > ogu && v[i] <= u)
                nrd++;
            else if(v[i] > u)
                break;
        }
        if(nrdm < nrd)
        {
            nrdm = nrd;
            r = u - ogu;
        }
        aux = u - ogu + 1;
        ogu = u;
        u += aux;
    }
    cout << r << '\n' << (n-1)*2;
    return 0;
}
