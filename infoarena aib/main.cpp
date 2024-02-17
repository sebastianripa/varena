#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("aib.in");
ofstream fout ("aib.out");

int n;
vector <int> v(100005, 0);
int vc[100005];

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
    int m, cer;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> vc[i];
        update(i, vc[i]);
    }
    for(int i = 1; i <= m; i++) {
        cin >> cer;
        if(cer == 0) {
            int a, b;
            cin >> a >> b;
            update(a, b);
        }
        else if(cer == 1) {
            int l, r;
            cin >> l >> r;
            cout << rougesum(l, r) << '\n';
        }
        else {
            int mij, l, r, a;
            cin >> a;
            l = 1;
            r = n;
            while(l <= r) {
                mij = (r+l)/2;
                int sum = presum(mij);
                if(sum == a) {
                    cout << mij << '\n';
                    break;
                }
                if(sum > a)
                    r = mij-1;
                else
                    l = mij+1;
            }
            if(l > r)
                cout << -1 << '\n';
        }
    }
    return 0;
}
