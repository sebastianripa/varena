#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("culori1.in");
ofstream out("culori1.out");
int v[1005],f[1005];
int main()
{
    int n,k,i,j,c,cnt=0,fmax;
    in>>n>>k;
    for(i=1;i<=n;++i)
    {
        in>>c;
        v[i]=c;
    }
    if(v[1]==v[n] && v[1]==v[2])
        cnt++;
    if(v[n-1]==v[n] && v[n]==v[1])
        cnt++;
    for(i=2;i<n;++i)
    {
        if(v[i-1]==v[i] && v[i]==v[i+1])
            cnt++;
    }
    out<<cnt<<'\n';
    i=0;fmax=-1;
   do
    {
        i++;
        int copk=k;
        fill(f+1,f+n+1,0);
        j=i;
        while(copk)
        {
            f[v[j]]++;
            copk--;
            if(j==n)
                j=1;
            else
                j++;
        }
        sort(f+1,f+n+1);
        reverse(f+1,f+n+1);
        if(f[1]>fmax)
            fmax=f[1];
    }while(i<n);
    out<<fmax;
    return 0;
}
