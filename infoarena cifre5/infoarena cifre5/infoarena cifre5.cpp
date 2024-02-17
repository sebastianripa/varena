#include <fstream>

using namespace std;

ifstream cin("cifre5.in");
ofstream cout("cifre5.out");

int v1[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int v2[] = { 2, 6, 2, 3, 3, 4, 2, 3, 1, 1 };
int v3[] = { 0, 1, 0, 0, 0, 0, 0, 2, 0, 1 };
int vf[10];
int vf1[10];

int main() {
    unsigned long long cer, n;
    cin >> cer >> n;
    if (cer == 1) {
        int nrs = 0;
        while (n) {
            nrs += v1[n % 10];
            n /= 10;
        }
        cout << nrs;
    }
    else {
        unsigned long long nrm = 0, cn = n, p = 1;
        bool ok = false;
        while (cn) {
            vf[cn % 10]++;
            cn /= 10;
            p *= 10;
            if (p == 10 && !ok) {
                p /= 10;
                ok = true;
            }
        }
        while (p) {
            vf1[n / p % 10]++;
            long long nrm1 = (v2[n / p % 10] - 1);
            for (int i = 0; i <= 9; i++) {
                long long nr = vf1[i];
                while (nr < vf[i] && vf[i]) {
                    nrm1 *= (v2[i] + v3[i]);
                    nr++;
                }
            }
            nrm += nrm1;
            p /= 10;
        }
        cout << nrm;
    }
}