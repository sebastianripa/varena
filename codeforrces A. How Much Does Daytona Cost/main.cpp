#include <iostream>

using namespace std;

int v[105];
int vf[105];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        for(int i = 1; i <= 100; i++)
            vf[i] = 0;
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            vf[v[i]]++;
        }
        if(vf[k] >= 1)
            cout << "YES" << '\n';
        else
            cout  << "NO" << '\n';
    }
    return 0;
}
