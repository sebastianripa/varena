#include <bits/stdc++.h>

using namespace std;

map <int, set<int>> adj;
set <int> v[3];
set <int>::iterator it;

int main()
{
    int n, m, n1, n2;
    int ok = 3;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> n1 >> n2;
        if(n1 > n2)
            swap(n1, n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    for(auto x : adj) {
        it = find(v[1].begin(), v[1].end(), x.first);
        if(it != v[1].end()) {
            for(auto y : x.second) {
                it = find(v[1].begin(), v[1].end(), y)
                if(it != v[1].end()) {
                    cout << "NU";
                    exit(0);
                }
                it = find(v[2].begin(), v[2].end(), y);
                if(it != v[2].end())
                    continue;
                v[2].insert(y);
            }
            continue;
        }
        it = find(v[2].begin(), v[2].end(), x.first);
        if(it != v[2].end()) {
            for(auto y : x.second) {
                it = find(v[2].begin(), v[2].end(), y)
                if(it != v[2].end()) {
                    cout << "NU";
                    exit(0);
                }
                it = find(v[1].begin(), v[1].end(), y);
                if(it != v[1].end())
                    continue;
                v[1].insert(y);
            }
            continue;
        }
        for(auto y : x.second) {
            it = find(v[1].begin(), v[1].end(), y);
            if(it != v[1].end()) {
                if(ok == 2) {
                    cout << "NU";
                    exit(0);
                }
                ok = 1;
                v[2].insert(y);
                continue;
            }
            it = find(v[2].begin(), v[2].end(), y);

        }
    }
    return 0;
}
