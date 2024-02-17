#include <fstream>
#include <vector>

using namespace std;

ifstream cin("joc11.in");
ofstream cout("joc11.out");

int v[905];
vector <int> elim;

int main()
{
    int n, m;
    cin >> n >> m;
    int mini = 21e8, juc, cg;
    for (int i = 1; i <= n; i++) {
        bool vf[9010];
        for (int j = 1; j <= m; j++)
            cin >> v[j], vf[j] = 0;
        int c = 1, e = 1;
        while (!vf[c]) {
            if (!v[c]) {
                elim.push_back(e);
                break;
            }
            if (v[c] == 9999) {
                if (mini > e) {
                    mini = e;
                    juc = i;
                    cg = c;
                }
                break;
            }
            vf[c] = 1;
            e += (v[c] % 10) + 1;
            c = v[c] / 10;
        }
    }
    int e = 0;
    for (auto x : elim) {
        if (mini >= x)
            e++;
    }
    cout << juc << ' ' << cg << ' ' << mini << ' ' << e;
    return 0;
}