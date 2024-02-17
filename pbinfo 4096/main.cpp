#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("balba.in");
ofstream fout ("balba.out");

int vf[10];

int main()
{
    int cer, n, x, nrc = 0, nrp = 0;
    cin >> cer >> n;


    if(cer == 1) {
        int ogx;
        cin >> ogx;
        nrc++;
        vf[ogx] = 1;
        for(int i = 2; i <= n; i++) {
            cin >> x;
            if(ogx != x)
                vf[ogx] = 0;
            if(!vf[x])
                nrc++;
            else if(vf[x] == 1)
                nrp++;
            vf[x]++;
            ogx = x;
        }
        cout << nrc << '\n' << nrp;
    }
    else {
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            vf[x]++;
        }
        for(int i = 9; i >= 1; i--) {
            if((vf[i]%2) && !ok && vf[i] != 0) {
                for(int j = 1; j <= vf[i]/2+1; j++)
                    cout << i;
                ok = true;
                int cnt = i;
                continue;
            }
            for(int j = 1; j <= vf[i]/2; j++)
                cout << i;
        }
        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= vf[i]/2; j++)
                cout << i;
        }
    }
    return 0;
}
