#include <bits/stdc++.h>

using namespace std;

vector <int> sol;
bool vf[10005];
int v[15];
int n;

bool prim(int a, int b) {
    int r = a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return (b == 1);
}

void bkt(int cn) {
    if(cn == 0) {
        for(auto x : sol)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        sol.push_back(v[i]);
        if((sol.size() <= 1 || prim(sol.rbegin()[1], sol.rbegin()[0])) && vf[v[i]])
        {   
            vf[v[i]] = 0;
            bkt(cn-1);
            vf[v[i]] = 1;
        }
        sol.pop_back();
    }
}

int main() {
    freopen("sirpie.in", "r", stdin);
    freopen("sirpie.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        vf[v[i]] = 1;
    }
    sort(v+1, v+n+1);
    bkt(n);
    return 0;
}
