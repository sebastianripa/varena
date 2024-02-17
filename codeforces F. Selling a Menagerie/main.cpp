#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

int p[N], c[N];
array<set<int>, N> adj;
bool cycle[N];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            adj[p[i]].insert(i);
        }
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        for(int i = 1; i <= n; i++) {
            if(adj[i].empty())
                cout << i << ' ';
            else
                cycle[i] = 1;
        }
    }
    return 0;
}
