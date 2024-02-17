#include <iostream>

using namespace std;

int v[10005];

int main()
{
    long long m, n;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    long long q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        if(c == 's') {
            long long s = 0, l, r, mod;
            cin >> l >> r >> mod;
            for(long long i = l; i <= r; i++) {
                if(v[i]%m == mod)
                    s += v[i];
            }
            cout << s << '\n';
        }
        else if(c == '+') {
            long long p, r;
            cin >> p >> r;
            v[p] += r;
            cout << v[p] << '\n';
        }
        else {
            long long p, r;
            cin >> p >> r;
            if(v[p] >= r)
                v[p] -= r;
            cout << v[p] << '\n';
        }
    }
    return 0;
}
