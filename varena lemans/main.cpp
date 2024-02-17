#include <bits/stdc++.h>

using namespace std;

ifstream in("lemans.in");
ofstream out("lemans.out");

int t,n,m,i,j,ans=INT_MAX,l,r,p1,p2;
int v[1001],p[1001],frq[1001],ansv[1001];
vector<pair<int,int>> vv;
bitset<1001>b;
map<int,int>mp;

int main()
{
    in>>t>>n>>m;
    for(i=1;i<=n;i++)
    {
        in>>v[i];
        v[i]*=t;
    }
    for(i=1;i<=m;i++)
    {
        in>>p[i];
        mp[p[i]]=i;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            vv.push_back(make_pair(v[i]+p[j],i));
    sort(vv.begin(),vv.end());
    for(p1=0;p1<vv.size();p1++)
    {
        for(;p2<vv.size()&&b.count()<n;p2++)
        {
            frq[vv[p2].second]++;
            if(frq[vv[p2].second]==1)
                b[vv[p2].second]=1;
        }
        if(b.count()==n)
            if(vv[p2-1].first-vv[p1].first<=ans)
            {
                ans=vv[p2-1].first - vv[p1].first;
                l=p1;
                r=p2-1;
            }
        frq[vv[p1].second]--;
        if(frq[vv[p1].second]==0)
            b[vv[p1].second]=0;
    }
    out << ans << '\n';
    for(i=l;i<=r;i++)
        ansv[vv[i].second] = mp[vv[i].first - v[vv[i].second]];
    for(i=1;i<=n;i++)
        out<<ansv[i]<<" ";
    return 0;
}
