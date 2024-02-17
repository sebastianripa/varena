#include <fstream>
#include <queue>

using namespace std;

ifstream cin("pereti.in");
ofstream cout("pereti.out");

queue <pair<int, int>> q;
int m[105][105], n, m1;
bool md[105][105];

int nrb2(int n) {
    int v[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int i = 4;
    while (n && i) {
        v[i--] = n % 2;
        n /= 2;
    }
    int nr = 0;
    for (int i = 1; i <= 4; i++)
        nr = nr * 10 + v[i];
    return nr;
}

void lee(pair<int, int> idx) {
    if (!q.empty())
        q.pop();
    int i = idx.first, j = idx.second;
    md[i][j] = true;
    int x = nrb2(m[i][j]);
    if (!(x % 10) && j > 1 && !md[i][j - 1]) {
        q.push({ i, j - 1 });
        md[i][j - 1] = true;
    }
    if (!(x / 10 % 10) && i < n && !md[i + 1][j]) {
        q.push({ i + 1, j });
        md[i + 1][j] = true;
    }
    if (!(x / 100 % 10) && j < m1 && !md[i][j + 1]) {
        q.push({ i, j + 1 });
        md[i][j + 1] = true;
    }
    if (!(x / 1000) && i > 1 && !md[i - 1][j]) {
        q.push({ i - 1, j });
        md[i - 1][j] = true;
    }
    if (q.empty())
        return;
    lee(q.front());
}

int32_t main() {
    cin >> n >> m1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m1; j++)
            cin >> m[i][j];
    }
    for (int i = 1; i <= m1; i++) {
        int bit = nrb2(m[1][i]);
        if (!(bit / 1000) && !md[1][i]) {
            if (i == 1 && bit / 100 % 10)
                continue;
            if (i == m1 && bit / 10 % 10)
                continue;
            if (bit / 1000)
                continue;
            lee({ 1, i });
        }
    }
    for (int i = 1; i <= n; i++) {
        int bit = nrb2(m[i][1]);
        if (!(bit / 100 % 10) && !md[i][1]) {
            if (i == 1 && bit / 1000)
                continue;
            if (i == n && bit / 10 % 10)
                continue;
            if (bit % 10)
                continue;
            lee({ i, 1 });
        }
    }
    for (int i = m1; i >= 1; i--) {
        int bit = nrb2(m[n][i]);
        if (!(bit / 10 % 10) && !md[n][i]) {
            if (i == 1 && bit / 100 % 10)
                continue;
            if (i == m1 && bit / 10 % 10)
                continue;
            if (bit / 10 % 10)
                continue;
            lee({ n, i });
        }
    }
    for (int i = n; i >= 1; i--) {
        int bit = nrb2(m[i][m1]);
        if (!(bit / 100 % 10) && !md[i][m1]) {
            if (i == 1 && bit / 1000)
                continue;
            if (i == n && bit / 10 % 10)
                continue;
            if (bit / 100 % 10)
                continue;
            lee({ i, m1 });
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m1; j++) {
            int bit = nrb2(m[i][j]);
            if (bit % 10) {
                if (j == 1)
                    ans++;
                if (md[i][j])
                    ans++;
            }
            if (bit / 10 % 10) {
                if (i == n)
                    ans++;
                if (md[i][j])
                    ans++;
            }
            if (bit / 100 % 10) {
                if (j == m1)
                    ans++;
                if (md[i][j])
                    ans++;
            }
            if (bit / 1000) {
                if (i == 1)
                    ans++;
                if (md[i][j])
                    ans++;
            }
        }
    }
    cout << ans;
}