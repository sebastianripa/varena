#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("pesti.in");
ofstream cout("pesti.out");

int main() {
    int n, x;
    cin >> n >> x;
    int nrz = int(log2(n - 1)), loc = x, pz = x, poz = 0, cnt = n;
    for (int i = 1; i <= nrz; i++) {
        int ll = loc;
        if (pz % 2) {
            loc = loc - pz + (pz / 2) + 1;
            cnt = (cnt + 1) / 2;
        }
        else {
            loc = loc - pz + ((cnt + 1) / 2) + (pz / 2);
            cnt /= 2;
        }
        if (loc != ll)
            poz = i;
        pz = (pz + 1) / 2;
        if (cnt <= 2) break;
    }
    cout << nrz << ' ' << loc << ' ' << poz;
}