#include <iostream>

using namespace std;

int v[200005];
pair<int, int> vs[200005];

int verifNxt(int st, int n, int v) {
    for(int i = st; i <= n && vs[i].f <= v; i++)
        continue;
    st = i;
    return st;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            vs[i].f = v[i];
            vs[i].s = i;
        }
        sort(vs+1, vs+n+1);
        int st = 1, h = vs[1].f, st2, add = 0;
        while(st <= n && w > 0) {
            st2 = verifNxt(st);
            add += st2 - st + 1;
            w -= add;
            h++;
        }
        if(st == n+1 && h < w) {
            w -= h;

        }
    }
    return 0;
}
