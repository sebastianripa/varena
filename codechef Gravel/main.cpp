#include <iostream>

using namespace std;

int sp[1000005], v[1000005];

void afisare(int idx) {
    v[1] = sp[1];
    for(int i = 2; i <= idx; i++)
        v[i] = v[i-1] + sp[i];
    cout << v[idx] << '\n';
}

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++)
        v[i] = c;
    while(m--) {
        char c;
        cin >> c;
        if(c == 'S') {
            int l, r, k;
            cin >> l >> r >> k;
            sp[l] += k;
            sp[r+1] -= k;
        }
        else {
            int idx;
            cin >> idx;
            afisare(idx);
        }
    }
    return 0;
}
