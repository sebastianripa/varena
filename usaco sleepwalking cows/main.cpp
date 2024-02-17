#include <bits/stdc++.h>

using namespace std;

int m;
vector <int> bits(100005, 0);
int v[100005];

void update(int i, int val) {
    while(i <= m) {
        bits[i] += val;
        i += (i&-i);
    }
}

int presum(int i) {
    int sum = 0;
    while(i > 0) {
        sum += bits[i];
        i -= (i&-i);
    }
    return sum;
}

int rougesum(int i, int j) {
    return presum(j) - presum(i-1);
}

int main()
{
    int n, k, x;
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        update(v[i], 1);
    }
    for(int i = 1; i <= k; i++) {
        int cer, a, b;
        cin >> cer >> a >> b;
        if(!cer) {
            update(v[a], -1);
            update(b, 1);
            v[a] = b;
        }
        else if(rougesum(a, b) > x)
            cout << rougesum(a, b) << '\n';
    }
    return 0;
}
