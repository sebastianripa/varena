#include <fstream>
#include <cmath>
using namespace std;
ifstream in("partitura.in");
ofstream out("partitura.out");
int v[10005];
int main()
{
    int n,i,cn=0,h=0;
    in>>n;
    for(i=1;i<=n;++i)
    {
        in>>v[i];
        if(v[i]!=1)
            h=h+v[i];
    }
    out<<h<<'\n';
    int d=0,cr=0;
    for(i=1;i<=n-1;++i)
    {
        if(v[i]<=v[i+1] && v[i]!=1 && v[i+1]!=1)
        {
            cr=cr+(max(v[i],v[i+1])-min(v[i],v[i+1]));
        }
        if(v[i]>=v[i+1] && v[i]!=1 && v[i+1]!=1)
        {
            d=d+(max(v[i],v[i+1])-min(v[i],v[i+1]));
        }
    }
    out<<max(d,cr)-min(d,cr)<<'\n';
    int cntmin=0,cntmaj=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]+3==v[i+1] && v[i+1]+2==v[i+2] && v[i]!=1 && v[i+1]!=1 && v[i+2]!=1)
            cntmaj++;
        if(v[i]+2==v[i+1] && v[i+1]+3==v[i+2] && v[i]!=1 && v[i+1]!=1 && v[i+2]!=1)
            cntmin++;
    }
    out<<cntmaj<<" "<<cntmin;
    return 0;
}
