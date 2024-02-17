#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout ("dijkstra.out");

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
map <int, vector<pair<int, int>>> adj;
vector <int> v(101, INF);

void dfs(int st) {
    pq.push(make_pair(0, st));
    v[st] = 0;
    while(!pq.empty()) {
        int nst = pq.top().s;
        pq.pop();
        for(auto x : adj[nst]) {
            if(v[x.f] > v[nst] + x.s) {
                v[x.f] = v[nst] + x.s;
                pq.push(make_pair(v[x.f], x.f));
            }
        }
    }
}

int main()
{
    int n, p, n1, n2, og1 = 0, og2 = 0, c;
    fin >> n >> p;
    while(!fin.eof()) {
        fin >> n1 >> n2 >> c;
        if(og1 != n1 || og2 != n2) {
            adj[n1].push_back(make_pair(n2, c));
        }
        og1 = n1;
        og2 = n2;
    }
    dfs(p);
    for(int i = 1; i <= n; i++) {
        if(v[i] == INF && i != p)
            fout << "-1 ";
        else
            fout << v[i] << ' ';
    }
    return 0;
}
