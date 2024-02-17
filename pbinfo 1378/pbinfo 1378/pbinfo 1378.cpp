#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

ifstream cin("flori2.in");
ofstream cout("flori2.out");

vector <int> v[100];
vector <int> sol[155];

struct DSU {
    vector <int> p, s;
    void init(int n) {
        p.resize(n + 1);
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }
    int f(int x) {
        if (x == p[x])
            return x;
        return p[x] = f(p[x]);
    }
    void unite(int x, int y) {
        x = f(x);
        y = f(y);
        if (x == y)
            return;
        if (s[x] > s[y])
            swap(x, y);
        else if (s[x] == s[y] && x < y)
            swap(x, y);
        p[x] = y;
        s[y] += s[x];
    }
};

int main() {
    DSU dsu;
    int n, m;
    cin >> n >> m;
    dsu.init(n);
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            maxx = max(maxx, x);
            v[x].push_back(i);
        }
    }
    for (int i = 0; i <= maxx; i++) {
        for (int j = 1; j < v[i].size(); j++)
            dsu.unite(v[i][j - 1], v[i][j]);
    }
    for (int i = 1; i <= n; i++)
        sol[dsu.p[i]].push_back(i);
    for (int i = 0; i <= n; i++) {
        for (auto x : sol[i])
            cout << x << ' ';
        if (sol[i].size())
            cout << '\n';
    }
}