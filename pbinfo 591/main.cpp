#include <bits/stdc++.h>
#define f first
#define s second
#define NMAX 1 << 31 - 1
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("firma.in");
ofstream fout ("firma.out");

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
map <long long, set<pair<long long, long long>>> adj;
vector <long long> v(101, NMAX);
pair<long long, long long> vf[101];
long long vf1[101];

void dfs(long long st) {
    pq.push(make_pair(0, st));
    v[st] = 0;
    while(!pq.empty()) {
        long long nst = pq.top().s;
        pq.pop();
        for(auto x : adj[nst]) {
            if(v[x.f] > v[nst] + x.s) {
                v[x.f] = v[nst] + x.s;
                pq.push(make_pair(v[x.f], x.f));
                if(vf[x.f].s > v[x.f]) {
                    vf[x.f].s = v[x.f];
                    vf[x.f].f = st;
                }
            }
        }
    }
}

int main()
{
    long long n, m, x1, x2, w, maxi = 0, ans, cv = INT_MAX;
    cin >> n >> m;
    for(long long i = 1; i <= m; i++) {
        cin >> x1 >> x2 >> w;
        adj[x1].insert(make_pair(x2, w));
        adj[x2].insert(make_pair(x1, w));
    }
    for(long long i = 1; i <= n; i++) {
        for(long long j = 1; j <= n; j++) {
            v[j] = cv;
            if(i == 1) {vf[j].f = cv; vf[j].s = cv;}
        }
        dfs(i);
    }
    for(long long i = 1; i <= n; i++) {
        vf1[vf[i].f]++;
        if(maxi < vf1[vf[i].f]) {
            maxi = vf1[vf[i].f];
            ans = vf[i].f;
        }
    }
    cout << ans;
    return 0;
}
