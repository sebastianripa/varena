#include <iostream>

using namespace std;
int ct;
bool ok;

int main()
{
    int n,m=1,g,cn2;
    cin>>n;
    int c=n;
    while(n)
    {
        ct++;
        n/=10;
    }
    for(int i=1;i<=ct/2;i++)
    {
        m=m*10;
        g=c%m;
        n=c;
        ok=true;
        while(n)
        {
            if(n%m!=g)
            {
                ok=false;
                break;
            }
            n=n/m;
        }
        if(ok==true)
            break;
    }
    if(ok==true)
        cout<<"DA";
    else cout<<"NU";
    return 0;
}
