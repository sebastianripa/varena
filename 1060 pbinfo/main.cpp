#include <bits/stdc++.h>

using namespace std;
ifstream fin("porumb.in");
ofstream fout("porumb.out");
int main()
{
    int n,x,cop,k,in,r,ok,p;
    fin>>n>>x;
    if(n%2)
        fout<<n/2+1<<'\n';
    else
        fout<<n/2<<'\n';
    cop=n;
    k=0;
    while(cop)
    {
        cop/=2;
        k++;
    }
    fout<<k<<'\n';
    if(x%2)
        fout<<1;
    else
    {
        int ans=1;
        while(x%2==0)
        {
            x/=2;
            ans++;
        }
        fout<<ans<<'\n';
    }
    in=1;
    r=2;
    for(int i=1; i<=k; i++)
    {
        p=in;
        in*=2;
        r*=2;
    }
    fout<<in/2;
    return 0;
}
