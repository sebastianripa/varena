#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("datorii.in");
ofstream fout ("datorii.out");

vector <int> v(15005, 0);
int vc[15005];
int n;

void update(int i, int val) {
    while(i <= n) {
        v[i] += val;
        i += (i&-i);
    }
}

int presum(int i) {
    int sum = 0;
    while(i > 0) {
        sum += v[i];
        i -= (i&-i);
    }
    return sum;
}

int rougesum(int i, int j) {
    return presum(j) - presum(i-1);
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> vc[i];
        update(i, vc[i]);
    }
    for(int i = 1; i <= m; i++) {
        int cer, a, b;
        cin >> cer >> a >> b;
        if(!cer)
            update(a, -b);
        else
            cout << rougesum(a, b) << '\n';
    }
    return 0;
}
