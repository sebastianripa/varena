#include <fstream>

using namespace std;

ifstream in ("platou.in");
ofstream out ("platou.out");

int m[1000001],r1[1000001],r2[1000001];

int main()
{
    int v,n,i,max=0;
    in>>v>>n;
    for(i=1;i<=n;i++)
    {
        in>>m[i];
        if(max<m[i])
            max=m[i];
    }
    if(v==1)
    {
        int lmax=1,l=1;
        for(i=2;i<=n;i++)
        {
            if(m[i]==m[i-1])
                l++;
            else
                l=1;
            if(lmax<l)
            {
                lmax=l;
                max=m[i];
            }
            else if(lmax==l && m[i]>max)
                max=m[i];
        }
        out<<lmax<<" "<<max;
    }
    else
    {
        int lmax=0,l=1;
        for(i=1;i<=n;i++)
        {
            if(m[i]==m[i-1])
                l++;
            else
                l=1;
            if(r1[m[i]]<l)
                r1[m[i]]=l;
            else if (r2[m[i]]<l)
                r2[m[i]]=l;
        }
        for(i=0;i<=max;i++)
        {
            if(r1[i]+r2[i]>=lmax)
            {
                lmax=r1[i]+r2[i];
                l=i;
            }
        }
        out<<lmax<<" "<<l;
    }
    return 0;
}
