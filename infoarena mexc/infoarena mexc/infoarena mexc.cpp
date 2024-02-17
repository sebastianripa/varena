#include <fstream>
#include <vector>

using namespace std;

ifstream cin("mexc.in");
ofstream cout("mexc.out");

int m[805][805], ans[805][805];
vector <pair<int, int>> v[100005];
int dc[4] = { 0, 1, 0, -1 };
int dr[4] = { -1, 0, 1, 0 };

bool verif(int l, int c, int n, int m) {
    if (l > n || l < 1 || c > m || c < 1)
        return false;
    return true;
}

struct DSU {
    vector <int> p, s;
    void init(int n) {
        p.resize(n + 1);
        s.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }
    int f(int x) {
        if (p[x] == x)
            return x;
        return p[x] = f(p[x]);
    }
    void unite(int x, int y) {
        x = f(x);
        y = f(y);
        if (x == y)
            return;
        if (s[x] < s[y])
            swap(x, y);
        s[x] += s[y];
        p[y] = x;
    }
};

int trns(int i, int j, int m) {
    return (i - 1) * m + j;
}

int main() {
    DSU dsu;
    int n, m1, k, maxx = 0, minn = 100000;
    cin >> n >> m1 >> k;
    dsu.init(n*m1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m1; j++) {
            cin >> m[i][j];
            v[m[i][j]].push_back({ i, j });
            maxx = max(maxx, m[i][j]);
            minn = min(minn, m[i][j]);
        }
    }
    for (int i = maxx + k + 1; i >= minn; i--) {
        for (int j = 0; j < v[i].size(); j++) {
            int aux = trns(v[i][j].first, v[i][j].second, m1);
            aux = dsu.f(aux);
            dsu.s[aux]++;
        }
        if (i - k > 0) {
            for (int j = 0; j < v[i - k].size(); j++) {
                for (int l = 0; l < 4; l++) {
                    int ln = v[i - k][j].first + dr[l];
                    int cl = v[i - k][j].second + dc[l];
                    if (verif(ln, cl, n, m1) && m[ln][cl] >= i - k)
                        dsu.unite(trns(ln, cl, m1), trns(v[i - k][j].first, v[i - k][j].second, m1));
                }
            }
        }
        for (int j = 0; j < v[i].size(); j++) {
            int aux = trns(v[i][j].first, v[i][j].second, m1);
            aux = dsu.f(aux);
            ans[v[i][j].first][v[i][j].second] = dsu.s[aux];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m1; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}