#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long v[1000005], vm[1000005];
vector <long long> bits(1000005, 0), v2(1000005, 0);
long long n;

void update(long long i, long long val) {
    while(i <= n) {
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

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    sort(v2.begin()+1, v2.begin()+n+1);
    for(long long i = n; i >= 1; i--) {
        long long idx = lower_bound(v2.begin(), v2.begin()+n+1, v[i]) - v2.begin();
        long long nrm = presum(idx);
        vm[idx] = nrm;
        update(idx, 1);
    }
    for(int i = 1; i <= n; i++)
        bits[i] = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        long long idx = lower_bound(v2.begin(), v2.begin()+n+1, v[i]) - v2.begin();
        long long nrm = i - presum(idx) - 1;
        ans += nrm*vm[idx];
        update(idx, 1);
    }
    cout << ans;
    return 0;
}
