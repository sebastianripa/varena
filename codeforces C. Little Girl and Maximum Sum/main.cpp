#include <iostream>
#include <algorithm>

using namespace std;

long long v[200005], sp[200005], vn[200005];

int main()
{
    long long n, q;
    cin >> n >> q;
    for(long long i = 1; i <= n; i++)
        cin >> v[i];
    sort(v+1, v+n+1);
    for(long long i = 1; i <= q; i++) {
        long long l, r;
        cin >> l >> r;
        sp[l]++;
        sp[r+1]--;
    }
    for(long long i = 1; i <= n; i++)
        vn[i] = sp[i] + vn[i-1];
    sort(vn+1, vn+n+1);
    long long ans = 0;
    for(long long i = 1; i <= n; i++)
        ans += vn[i]*v[i];
    cout << ans;
    return 0;
}
