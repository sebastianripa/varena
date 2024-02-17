#include <fstream>
using namespace std;
ifstream in("vase.in");
ofstream out("vase.out");
int main()
{
    int n,i,x,v[100005];long long s=0,s2=0,st,dr;char d[100005];
    in>>n;
    for(i=1;i<=n;++i)
    {
        in>>v[i]>>d[i];
        s=s+v[i];
    }
    in>>x;
    for(i=1;i<x;++i)
        s2=s2+v[i];
    s2=s2/2;
    i=x;
    if(d[i]=='S')
    {
        st=-s2-v[i]/2;
        dr=-s2+v[i]/2;
    }
    else
    {
        st=s2-v[i]/2;
        dr=s2+v[i]/2;
    }
    for(i=x+1;i<=n;++i)
    {
        if(d[i]=='S')
        {
            st=st+v[i]/2;
            dr=dr+v[i]/2;
        }
        else
        {
            st=st-v[i]/2;
            dr=dr-v[i]/2;
        }
    }
    out<<s/2<<"\n";
    if(st>=0)
        out<<dr<<" D\n"<<st<<" D\n";
    else
        if(dr<=0)
            out<<-st<<" S\n"<<-dr<<" S\n";
        else
            out<<-st<<" S\n"<<dr<<" D\n";
    return 0;
}
