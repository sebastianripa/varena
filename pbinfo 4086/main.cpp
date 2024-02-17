/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

#include <fstream>
using namespace std;
unsigned long long v[100005];
unsigned long long st[50005], dr[50005];
int main(){

    ifstream cin ("cmmdc.in");
    ofstream cout ("cmmdc.out");
    unsigned long long n, cer, a, b, r=0, ok=0, ok1=0, ca, max=0;
    cin >> cer;
    if(cer==1)
    {
        long long rest=0;
         cin >> n;
        cin >> a;
        for(long long i=1; i<=n-1; i++)
        {
            cin >> v[i];
            b=v[i];
            while(b!=0)
            {
                rest=a%b;
                a=b;
                b=rest;
            }
        }
        cout << a;
    }
    if(cer==2)
    {
        cin >> n;
        for(long long i=1; i<=n; i++)
        {
            cin >> v[i];
        }
        st[1]=v[1];
       // max=st[2];
        dr[n]=v[n];
        for(long long i=1; i<=n; i++)
        {

                //cout << i << "P" << endl;
                a=st[i-1];
                b=v[i];
                while(b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
                st[i]=a;

            a=0;
            b=0;
            r=0;
        }
        for(long long i=n; i>=1; i--)
        {

                //cout << i << "!" << endl;
                b=v[i];
                a=dr[i+1];
                while(b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
                dr[i]=a;

            a=0;
            b=0;
            r=0;
        }
        for(long long i=2; i<=n-1; i++)
        {

                r=0;
                a=st[i-1];
                b=dr[i+1];
                while(b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
              //  co
                if(a>max)
                {
                    max=a;

                }

        }
                a=dr[2];
                if(a>max)
                {
                    max=a;
                }

                a=st[n-1];
                if(a>max)
                {
                    max=a;
                }

        cout << max;
    }
    if(cer==3)
    {
        cin >> n;
        long long rest=0;
        for(long long  i=1; i<=n; i++)
        {
            cin >> v[i];
        }
        for(long long  k=1; k<=n; k++)
        {
            for(long long  i=1; i<=n; i++)
            {
                for(long long j=1; j<=n; j++)
                {
                    if(i!=j && ok==0 && j!=k)
                    {
                        a=v[j];
                        ok=1;
                    }
                    else if(i!=j && ok==1 && j!=k)
                    {
                        b=v[j];
                        while(b!=0)
                        {
                            rest=a%b;
                            a=b;
                            b=rest;
                        }
                    }
                }
            //    cout << a << endl;
                if(a>max)
                {
                    max=a;
                }
                ok=0;
                rest=0;
                b=0;
                a=0;
            }
        }
        cout << max;
    }

}
