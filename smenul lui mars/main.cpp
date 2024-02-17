#include <iostream>

using namespace std;

int v[200001], d[200001];

void update(int l, int r, int x, int n) {
    d[l] += x;
    d[r+1] -= x;
 }

int main() {
    int n, l, r, x, q;
    cin >> n;
//    for(int i = 1; i <= n; i++)
//        v[i] = i;
    d[1] = v[1];
    for(int i = 2; i <= n; i++)
        d[i] = v[i] - v[i-1];
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> l >> r >> x;
        update(l, r, x, n);
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1)
            v[i] = d[i];
        else
            v[i] = d[i] + v[i-1];
        cout << v[i] << ' ';
    }
    return 0;
}
