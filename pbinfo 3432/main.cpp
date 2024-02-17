#include <bits/stdc++.h>
using namespace std;

ifstream in("tai.in");
ofstream out("tai.out");

bool prim(int x)
{
    if(x<2) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3; i*i<=x; i+=2)
        if(x%i==0) return 0;
    return 1;
}

int nrCif(int x)
{
    int k=0;
    while(x)
    {
        x/=10;
        k++;
    }
    return k;
}

int v[105];

int main()
{
    int t, n, i, m=0, p;
    in>>t>>n;
    for(i=1; i<=n; i++) in>>v[i];
    if(t==1)
    {
        for(i=1; i<=n; i++)
        {
            if(prim(v[i]))
                m=max(m, v[i]);
        }
        out<<m;
    }
    else if(t==2)
    {
        int a, b;
        for(i=1; i<=n; i++)
        {
            p=100;
            a=v[i]/10;
            b=v[i]%10;
            do
            {
                if(prim(a)) m=max(m,a);
                if(prim(b)) m=max(m,b);
                a=v[i]/p;
                b=v[i]%p;
                p*=10;
            }while(a);
        }
        out<<m;
    }
    else
    {
        int a, b, c, d;
        for(i=1; i<=n; i++)
        {
            d=v[i]%10;
            c=v[i]/10;
            if(prim(d)) m=max(m, d);
            p=100;
            a=c/10;
            b=c%10;
            do
            {
                if(prim(a)) m=max(m,a);
                if(prim(b)) m=max(m,b);
                a=c/p;
                b=c%p;
                p*=10;
            }while(a);

            int cif=nrCif(v[i]);
            int pp=1;
            for(int j=1; j<=cif-1; j++) pp*=10;
            d=v[i]/pp;
            c=v[i]%pp;
            p=100;
            a=c/10;
            b=c%10;
            do
            {
                if(prim(a)) m=max(m,a);
                if(prim(b)) m=max(m,b);
                a=c/p;
                b=c%p;
                p*=10;
            }while(a);
        }
        out<<m;
    }
    return 0;
}
