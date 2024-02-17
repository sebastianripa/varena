#include <iostream>

using namespace std;

char v[200005];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k, nrb = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] == 'B')
                nrb++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == 'B') {
                int ck = k;
                while(ck--) {
                    if(v[i++] == 'B')
                        nrb--;
                }
                i--;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
