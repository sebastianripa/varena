#include <iostream>

using namespace std;

int v[100001], vms[100001], vmd[100001];

int main()
{
    int n, nrm = 0, i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++)
        vmd[i] = max(vmd[i-1], v[i]);
    for(i = n; i >= 1; i--)
        vms[i] = max(vms[i+1], v[i]);
    for(i = 1; i <= n; i++)
        nrm += min(vms[i], vmd[i]) - v[i];
    cout << nrm;
    return 0;
}
