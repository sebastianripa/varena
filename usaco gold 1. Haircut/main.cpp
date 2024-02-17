#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("haircut.in");
ofstream fout ("haircut.out");

long long n;
vector<long long> bits(100005, 0);
long long vf[100005];

void update(long long i, long long val) {
    while(i <= n+1) {
        bits[i] += val;
        i += (i&-i);
    }
}

long long presum(long long i) {
    long long sum = 0;
    while(i > 0) {
        sum += bits[i];
        i -= (i&-i);
    }
    return sum;
}

long long rougesum(long long i, long long j) {
    return presum(j) - presum(i-1);
}

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        vf[x+1] += i - presum(x+1) - 1;
        update(x+1, 1);
    }
    for(long long i = 1; i <= n; i++) {
        vf[i-1] = vf[i-1] + vf[i-2];
        cout << vf[i-1] << '\n';
    }
    return 0;
}
