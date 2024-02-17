#include <fstream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

ifstream cin ("closing.in");
ofstream cout ("closing.out");

vector<int> adj[200005];
int a[200005];
int b[200005],ordine[200005],nr[200005];
long long maxx=1;
stack<string> ans;

struct DSU {
    vector <long long> p, s;
    void init(long long n) {
        p.resize(n+1);
        s.resize(n+1);
        for(long long i = 1; i <= n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }
    long long f(long long x) {
        if(x == p[x])
            return x;
        return p[x] = f(p[x]);
    }
    void unite(long long x, long long y) {
        x = f(x);
        y = f(y);
        if(x == y)
            return;
        if(s[x] > s[y])
            swap(x, y);
        p[x] = y;
        s[y] += s[x];
        maxx=max(maxx,s[y]);
    }
};
    DSU barns;

int main()
{
    long long n, m;
    int rasp=0;
    cin >> n >> m;
    barns.init(n);
    for(long long i = 0; i < m; i++) {
            cin>>a[i]>>b[i];
    }
    for(long long i = 0; i < n; i++) {
        cin>>nr[i];
        ordine[nr[i]]=i;
    }
    for(int i=0;i<m;i++)
    {
        if(ordine[a[i]] > ordine[b[i]])
        {
            adj[b[i]].push_back(a[i]);
            continue;
        }
        adj[a[i]].push_back(b[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        int x=nr[i];
        rasp++;
        for(auto var : adj[x])
        {
            if(barns.f(var) != barns.f(x))
            {
                rasp--;
                barns.unite(x,var);
            }
        }
        //cout<<i<<' '<<rasp<<'\n';
        if(rasp>1)
        ans.push("NO");
        else
        ans.push("YES");
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<'\n';
        ans.pop();
    }
    return 0;
}
