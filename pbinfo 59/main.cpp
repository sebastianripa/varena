#include <iostream>

using namespace std;
int v[1001];

int main()
{
    int n, i, nrmax = 0, nrp = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        if(nrmax < v[i])
            nrmax = v[i];
    }
    for(i = 1; i <= n; i++)
        nrp += nrmax - v[i];
    cout << nrp;
    return 0;
}
