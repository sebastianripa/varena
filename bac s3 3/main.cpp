#include <iostream>

using namespace std;

int main()
{
    int a, b, c, r, p = 1,cmmmc;
    cin >> a >> b >> c;
    p=a*b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    ///In "a" memoram cmmdc(a,b)
    cmmmc=p/a;
    p=cmmmc*c;
    a=cmmmc;
    /**
    Reciclam varibabila a, in care memoram cmmmc(a,b)
    Apoi, vom face cmmdc(noul_a,c)


    */
    while(c)///Facem cmmdc(a,c)
    {
        r=a%c;
        a=c;
        c=r;
    }
    cmmmc=p/a;
    cout<<cmmmc;

}
