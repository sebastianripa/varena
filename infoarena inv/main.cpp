#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("inv.in");
ofstream fout ("inv.out");

int n;
vector <int> bits(100005);

void update(int i, int val) {
    while(i <= n) {
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

int main()
{
    cin >> n;
    vector <int> v(n);
    vector <int> v2(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    sort(v2.begin(), v2.end());
    long long inv = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        temp = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() + 1;
        inv += i - presum(temp);
        if(inv >= 9917)
            inv %= 9917;
        update(temp, 1);
    }
    cout << inv;
    return 0;
}
