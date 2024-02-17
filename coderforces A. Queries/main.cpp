#include <iostream>

using namespace std;

//ifstream cin ("test.in");
//ofstream cout ("test.out");

long long v[10005];
long long bits[15][10005];
long long n;

void update(long long i, long long val, long long m) {
    while(i <= n) {
        bits[m][i] += val;
        i += (i&-i);
    }
}

long long presum(long long i, long long m) {
    long long sum = 0;
    while(i > 0) {
        sum += bits[m][i];
        i -= (i&-i);
    }
    return sum;
}

long long rougesum(long long i, long long j, long long m) {
    return presum(j, m) - presum(i-1, m);
}

int main()
{
    long long m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++) {
        cin >> v[i];
        update(i, v[i], v[i]%m);
    }
    long long q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        if(c == '+') {
            long long i, val;
            cin >> i >> val;
            update(i, -v[i], v[i]%m);
            v[i] += val;
            update(i, v[i], v[i]%m);
            cout << v[i] << '\n';
        }
        else if(c == '-') {
            long long i, val;
            cin >> i >> val;
            if(v[i] >= val) {
                update(i, -v[i], v[i]%m);
                v[i] -= val;
                update(i, v[i], v[i]%m);
            }
            cout << v[i] << '\n';
        }
        else {
            long long l, r, mod;
            cin >> l >> r >> mod;
            cout << rougesum(l, r, mod) << '\n';
        }
    }
    return 0;
}
