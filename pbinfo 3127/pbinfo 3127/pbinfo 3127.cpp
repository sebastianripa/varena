#include <fstream>
#include <vector>
#define MAXN 10000

using namespace std;

ifstream cin("arbori_xor.in");
ofstream cout("arbori_xor.out");

int sum[MAXN + 1], ok[MAXN + 1];
vector <pair<int, int>> v[MAXN + 1];

void dfs(int ind, int nr) {
    ok[ind] = 1;
    sum[ind] = nr;
    for (auto i : v[ind])
        if (!ok[i.first])
            dfs(i.first, nr ^ i.second);
}

int main() {
    int n, q;
    cin >> n >> q;
    int a, b, nr;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> nr;
        v[a].push_back({ b, nr });
        v[b].push_back({ a, nr });
    }
    dfs(1, 0);
    while (q > 0) {
        cin >> a >> b;
        cout << (sum[b] ^ sum[a]) << '\n';
        q--;
    }
}