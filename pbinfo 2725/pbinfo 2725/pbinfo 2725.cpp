#include <iostream>
#include <cmath>

using namespace std;

int v[200005], vsq[470], bs;

void init(int n) {
    int bi = -1;
    bs = sqrt(n);
    for (int i = 0; i < n; i++) {
        if (i % bs == 0)
            bi++;
        vsq[bi] = min(vsq[bi], v[i]);
    }
}

void update(int pz, int val) {
    vsq[pz / bs]++;
}

int query(int l, int r) {
    int sum = 0;
    while (l < r && l % bs != 0) {
        sum += v[l];
        l++;
    }
    while (l + bs - 1 <= r)
        sum += vsq[l / bs], l += bs;
    while (l <= r) {
        sum += v[l];
        l++;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    bs = sqrt(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << query(0, x) << ' ';
        update(x, 1);
        v[x]++;
    }
}