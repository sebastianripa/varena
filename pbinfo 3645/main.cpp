#include <iostream>

using namespace std;

long long v[10001];

int main()
{
    long long c, n, x, maxi = 0, i, j, cont = 0;
    cin >> c >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            if(v[i]%2 == 0)
                cont++;
            else
            {
                maxi = max(maxi, cont);
                cont = 0;
            }
        }
        maxi = max(maxi, cont);
        cout << maxi;
    }
    else
    {
        cont = v[1];
        for(i = 2; i <= n; i++)
        {
            if(v[i] < v[i-1])
                cont += v[i];
            else
            {
                maxi = max(maxi, cont);
                cont = v[i];
            }
        }
        maxi = max(maxi, cont);
        cout << maxi;
    }
    return 0;
}
