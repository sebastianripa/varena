#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

ifstream cin("qvect.in");
ofstream cout("qvect.out");

int z[500005], v[105][5005];

int sol1(int x, int y) {
    int mini = 21e8, i = 1, j = 1;
    while (i <= v[x][0] && j <= v[y][0]) {
        mini = min(mini, abs(v[x][i] - v[y][j]));
        if (v[x][i] > v[y][j])
            j++;
        else
            i++;
    }
    return mini;
}

int sol2(int x, int y) {
    int i, nr = 1;
    for (int k = x; k <= y; k++) {
        for (i = 1; i <= v[k][0]; i++)
            z[nr++] = v[k][i];
    }
    nr--;
    nth_element(z + 1, z + (nr / 2), z + nr + 1);
    return z[nr / 2];
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        v[i][0] = k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            cout << sol1(x, y) << '\n';
        else cout << sol2(x, y) << '\n';
    }
}