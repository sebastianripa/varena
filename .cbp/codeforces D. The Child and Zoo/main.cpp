#include <bits/stdc++.h>

using namespace std;

vector <int> mini;
long long vf[100005], nrm, v[100005];
double s = 0;
map <int, set<int>> adj;

void dfs(int st) {
    vf[st] = 1;
    for(auto x : adj[st]) {
        if(!vf[x]) {
            long long aux = mini.back();
            mini.push_back(min(aux, v[x-1]));
            aux = mini.back();
            //double mini1 = (double)aux/nrm;
            s += aux;
            dfs(x);
            mini.pop_back();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    nrm = n*(n-1);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }
    for(int i = 1; i <= n; i++) {
        for(int i = 1; i <= n; i++)
            vf[i] = 0;
        mini.push_back(v[i-1]);
        dfs(i);
        mini.pop_back();
    }
    int x = (int)s, nrc = 0;
    while(x) {
        nrc++;
        x /= 10;
    }
    cout << setprecision(nrc+5) << s;
    return 0;
}
