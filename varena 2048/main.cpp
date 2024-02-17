#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("2048.in");
ofstream fout ("2048.out");

int v[10005];

int main() {
    int n, m, nrm = 0, maxi = 0, nrfm = 0;
    char c;
    bool ok = true;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    while(m-- && ok && maxi != 2048) {
        nrm++;
        int cn = n;
        int nrz = 0;
        int nrf = 0;
        ok = false;
        cin >> c;
        if(c == 'D') {
            for(int i = n-1; i >= 1; i--) {
                if(v[i+1] == v[i] && v[i] != 0) {
                    v[i+1] *= 2;
                    v[i] = 0;
                    i--;
                    ok = true;
                    nrf++;
                }
            }
            nrfm = max(nrf, nrfm);
            for(int i = n; i >= 1; i--) {
                bool ok1 = false, ok2 = false;
                maxi = max(v[i], maxi);
                if(v[i+nrz] == 0 && i != n && v[i]) {
                    v[i+nrz] = v[i];
                    v[i] = 0;
                    ok2 = true;
                }
                if(v[i] == 0 && !ok2) {
                    nrz++;
                    ok1 = true;
                }
            }
        }
        else {
            for(int i = 2; i <= n; i++) {
                if(v[i-1] == v[i] && v[i]) {
                    v[i-1] *= 2;
                    v[i] = 0;
                    i++;
                    ok = true;
                    nrf++;
                }
            }
            nrfm = max(nrf, nrfm);
            for(int i = 1; i <= n; i++) {
                bool ok1 = false, ok2 = false;
                maxi = max(v[i], maxi);
                if(v[i-nrz] == 0 && i != 1 && v[i]) {
                    v[i-nrz] = v[i];
                    v[i] = 0;
                    ok1 = true;
                }
                if(v[i] == 0 && !ok1) {
                    nrz++;
                    ok2 = true;
                }
            }
        }
    }
    while(!nrm && m--)
        cin >> c;
    if(maxi == 2048 || m == -1)
        cout << nrm << '\n';
    else
        cout << nrm-1 << '\n';
    cout << maxi << '\n' << nrfm;
}
