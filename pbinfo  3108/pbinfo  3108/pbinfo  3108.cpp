#include <fstream>
#include <cmath>
#include <algorithm>
#define int long long

using namespace std;

ifstream cin("dss.in");
ofstream cout("dss.out");

const int NMAX = 4e5 + 5, mod = 1000000007;

struct query {
    int l, r, i;
};

query q[NMAX];
int v[NMAX], bucket[NMAX], vf[NMAX], ans[NMAX];

void build(int n) {
    int bs = sqrt(n);
    for (int i = 1; i <= n; i++)
        bucket[i] = (i - 1) / bs + 1;
}

int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b % 2)
            ans = (ans * a) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int div1(int ans, int b) {
    return (ans * (pow(b, mod - 2) % mod)) % mod;
}

void update(int n, int d, int &ans) {
    ans = div1(ans, vf[n] + 1);
    vf[n] += d;
    ans *= (vf[n] + 1) % mod;
}

void solve(int m) {
    int l = 1, r = 0, ans1 = 1;
    for (int i = 1; i <= m; i++) {
        while (l < q[i].l) update(v[l++], -1, ans1);
        while (r < q[i].r) update(v[++r], 1, ans1);
        while (l > q[i].l) update(v[--l], 1, ans1);
        while (r > q[i].r) update(v[r--], -1, ans1);
        ans[q[i].i] = ans1 - 1;
    }
}

bool cmp(query a, query b) {
    if (bucket[a.l] != bucket[b.l])
        return a.l < b.l;
    return a.r < b.r;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(n);
    for (int i = 1; i <= m; i++)
        cin >> q[i].l >> q[i].r, q[i].i = i;
    sort(q + 1, q + m + 1, cmp);
    solve(m);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}