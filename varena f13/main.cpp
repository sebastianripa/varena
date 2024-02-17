#include <fstream>
#include <cstring>

using namespace std;

ifstream in("cursaf13.in");
ofstream out("cursaf13.out");

int main()
{
    string c;
    char c1;
    int i,j,d,t,p=1,b=0,m,l,t1;
    bool ok=0;
    in>>i>>j>>c>>t;
    l=strlen(c.c_str());
    c1=c[0];
    while(c[p]>='0' && c[p]<='9')
    {
        b=b*10+(c[p]-48);
        p++;
    }
    t1=b;
    for(int a=1; a<=t; a++)
    {
        in>>d;
        if(d%t1==0 && ok)
        {
            d=(d-1)/t1;
            d*=t1;
        }
        else
            while(d>t1 && d%t1 && ok)
                d-=t1;
        while(d && b)
        {
            m=min(d,b);
            if(c1=='A')
            {
                i-=m;
                d-=m;
                b-=m;
            }
            else if(c1=='B')
            {
                i-=m;
                j+=m;
                d-=m;
                b-=m;
            }
            else if(c1=='C')
            {
                j+=m;
                d-=m;
                b-=m;
            }
            else if(c1=='D')
            {
                i+=m;
                j+=m;
                d-=m;
                b-=m;
            }
            else if(c1=='E')
            {
                i+=m;
                d-=m;
                b-=m;
            }
            else if(c1=='F')
            {
                i+=m;
                j-=m;
                d-=m;
                b-=m;
            }
            else if(c1=='G')
            {
                j-=m;
                d-=m;
                b-=m;
            }
            else if(c1=='H')
            {
                i-=m;
                j-=m;
                d-=m;
                b-=m;
            }
            if(b==0)
            {
                c1=c[p];
                p++;
                while(c[p]>='0' && c[p]<='9')
                {
                    b=b*10+(c[p]-48);
                    p++;
                }
                if(ok==0)
                    t1+=b;
            }
            if(p==l)
                p=0, ok=1;
        }
        out<<i<<' '<<j<<'\n';
    }
    return 0;
}
