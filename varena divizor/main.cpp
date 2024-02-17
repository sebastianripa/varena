#include <fstream>

using namespace std;

ifstream in ("divizor.in");
ofstream out ("divizor.out");

int v[7];
int main()
{
    int n,c=0,i,f=1,max,j,maxi=1,s;
    in>>n;
    v[1]=n;
    for(j=1;j<=n/2+1;j++)
            if(v[1]%j==0)
                s++;
    max=s;
    while(n)
    {
        n=n/10;
        c++;
    }
    for(i=2;i<=c;i++)
        f=f*10;
    for(i=2;i<=c;i++)
    {
        s=0;
        v[i]=(v[i-1]%f)*10+v[i-1]/f;
        for(j=1;j<=n/2+1;j++)
            if(v[i]%j==0)
                s++;
        if(s>max)
        {
            maxi=i;
            max=s;
        }
    }
    out<<v[maxi]<<'\n';
}
