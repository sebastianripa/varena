#include <bits/stdc++.h>

using namespace std;

ifstream fin ("order.in");
ofstream fout ("order.out");

vector <int> bits(30005, 0);
int n;

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

int cb(int l, int r, int val) {
    int mid, sol = -1;
    while(l < r) {
        mid = (l+r)/2;
        if(presum(mid) >= val)
            r = mid, sol = mid;
        else
            l = mid+1;
    }
    if(sol == -1)
        sol = l;
    return sol;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        update(i, 1);
    int poz = 1;
    for(int i = 1; i <= n; i++) {
        int poz1 = (i%(n-i+1) + presum(poz))%(n-i+1);
        if(poz1 == 0)
            poz1 = (n-i+1);
        poz = cb(1, n, poz1);
        fout << poz << ' ';
        update(poz, -1);
    }
    return 0;
}
