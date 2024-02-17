#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

long long v[100005], sp[100005], sp1[100005];
pair<long long, pair<long long, long long>> vq[100005];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    for(long long i = 1; i <= n; i++)
        cin >> v[i];
    for(long long i = 1; i <= m; i++) {
        long long l, r, d;
        cin >> l >> r >> d;
        vq[i].f = l;
        vq[i].s.f = r;
        vq[i].s.s = d;
    }
    sp[1] = v[1];
    for(long long i = 2; i <= n; i++)
        sp[i] = v[i] - v[i-1];
    for(long long i = 1; i <= k; i++) {
        long long x, y;
        cin >> x >> y;
        sp1[x]++;
        sp1[y+1]--;
    }
    for(long long i = 1; i <= m; i++) {
        sp1[i] = sp1[i-1] + sp1[i];
        sp[vq[i].f] += vq[i].s.s*sp1[i];
        sp[vq[i].s.f+1] -= vq[i].s.s*sp1[i];
    }
    v[1] = sp[1];
    cout << v[1] << ' ';
    for(long long i = 2; i <= n; i++) {
        v[i] = v[i-1] + sp[i];
        cout << v[i] << ' ';
    }
    return 0;
}
