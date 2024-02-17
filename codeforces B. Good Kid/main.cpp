#include <iostream>

using namespace std;

int v[14];

int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int mini = 10;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            mini = min(mini, v[i]);
        }
        long long p = 1;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(v[i] != mini || !ok)
                p *= v[i];
            else if(ok) {
                v[i]++;
                p *= v[i];
                ok = false;
            }
        }
        cout << p << '\n';
    }
    return 0;
}
