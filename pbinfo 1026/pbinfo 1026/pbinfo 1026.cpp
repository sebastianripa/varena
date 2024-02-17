#include <fstream>

using namespace std;

ifstream cin("pseudobil.in");
ofstream cout("pseudobil.out");

bool m[1505][1505];
int sp[1505][1505];

int main() {
    int cer, n, k, d;
    cin >> cer >> n >> k >> d;
    if (cer == 1) {
        int nr = (d - 4) / 2;
        if (nr < 0) {
            cout << 1;
            return 0;
        }
        if (nr == 0) {
            cout << 5;
            return 0;
        }
        int ans = (d - 1) * 2 - 1;
        ans += (nr * (nr + 1) * 2);
        cout << ans;
    }
    else {
        for (int i = 1; i <= k; i++) {
            int x, y;
            cin >> x >> y;
            m[x][y] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                sp[i][j] = sp[i][j - 1] + m[i][j];
        }
        int m1;
        cin >> m1;
        for (int i = 1; i <= m1; i++) {
            int x, y;
            cin >> x >> y;
            int ans = 0;
            for (int j = 1; j <= d / 2; j++) {
                int x1 = y + j - 1, y1 = y - j;
                ans += sp[x + j - 1][x1] - sp[x + j - 1][y1];
                int xt = x + d;
                ans += sp[xt - j + 1][x1] - sp[xt - j + 1][y1];
            }
            int j = d / 2;
            int x1 = y + j, y1 = y - j - 1;
            ans += sp[x + j][x1] - sp[x + j][y1];
            cout << ans << '\n';
        }
    }
}