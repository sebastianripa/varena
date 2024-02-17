#include <bits/stdc++.h>

using namespace std;

ifstream fin ("wormsort.in");
ofstream fout ("wormsort.out");

struct pii {
    int first;
    pair <int, int> second;
};

int v[100005];
pii vw[100005];

struct DSU {
    vector <int> p, s;
    void init(int n) {
        p.resize(n+1);
        s.resize(n+1);
        for(int i = 1; i <= n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }
    int f(int x) {
        if(p[x] == x)
            return x;
        return p[x] = f(p[x]);
    }
    void unite(int x, int y) {
        x = f(x);
        y = f(y);
        if(x == y)
            return;
        if(s[x] > s[y])
            swap(x, y);
        p[x] = y;
        s[y] += s[x];
        s[x] = 0;
    }
};

int cmp(pii a, pii b) {
    if(a.second.second != b.second.second)
        return a.second.second > b.second.second;
    if(a.second.first != b.second.first)
        return a.second.first > b.second.first;
    return a.first > b.first;
}

int main()
{
    int n, m;
    DSU morbius;
    fin >> n >> m;
    morbius.init(n);
    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int i = 1; i <= m; i++) {
        int n1, n2, w;
        fin >> n1 >> n2 >> w;
        vw[i].first = n1;
        vw[i].second.first = n2;
        vw[i].second.second = w;
    }
    sort(vw+1,  vw+m+1, cmp);
    int mini = 0, i = 0;
    bool ok = 0;
    v[0] = 0;
    morbius.p[0] = 0;
    for(i = 1; i <= m; i++) {
        mini = vw[i].second.second;
        morbius.unite(vw[i].first, vw[i].second.first);
        int b = morbius.f(1), j = 1;
        for(; j <= n; j++) {
            if(morbius.f(j) != b && v[j] != j) {
                ok = 1;
                break;
            }
        }
        if(j == n+1)
            break;
    }
    if(!ok)
       mini = -1;
    fout << mini;
    return 0;
}
