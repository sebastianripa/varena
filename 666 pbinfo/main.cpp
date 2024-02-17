#include <iostream>

using namespace std;

int a[100][100];

int prim(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, m, i, j, nrp = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(i%2 == 0 && prim(a[i][j]))
                nrp++;
        }
    }
    cout << nrp;
    return 0;
}
