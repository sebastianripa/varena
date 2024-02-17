#include <iostream>
#include <fstream>
using namespace std;
ifstream in("palindrom1.in");
ofstream out("palindrom1.out");
int v[20];
int main()
{
    int n,amax=-1,cmax=-1,x,j,i,l,ok=0,ok2=0;
    in>>n;
    while(n--)
    {
        in>>x;
        v[x]++;
    }
    for(i=0; i<=9; i++)
    {
        if(v[i]%2)
            if(amax<v[i])
            {
                amax=v[i];
                cmax=i;
            }
            else if(amax==v[i])
                cmax=i;
    }
    for(i=9;i>=0;i--)
    {
        if(v[i]%2)
            v[i]=0;
        else if(v[i]%2==0 && v[i]){
            if(cmax>i && ok2==0){
                ok2=1;
                for(l=1;l<=amax/2;l++)
                    out<<cmax;
            amax/=2;
            }
            if(i>0)
                ok=1;
            for(j=1;j<=v[i]/2 && ok==1;j++)
                out<<i;
        v[i]/=2;
        }
    }
    out<<cmax;
    if(ok2==0)
        amax--;
    for(i=0;i<=9;i++)
    {
        if(v[i]){
            if(i>cmax)
            {
                for(l=1;l<=amax;l++)
                    out<<cmax;
                amax=0;
            }
            while(v[i]-- && ok==1)
                out<<i;
        }
    }
    if(amax)
        while(amax--)
            out<<cmax;
    return 0;
}
