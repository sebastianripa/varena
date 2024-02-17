#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("diagonal.in");
ofstream out("diagonal.out");
char v[10005];
char a[100][100];
int main()
{
    char x;
    int k=0,i=1,n,j,m;
    while(in>>x)
    {
        v[i]=x;
        i++;
    }
    int l=1;
    n=sqrt(i);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=v[l];
            l++;
        }
    for(i=n; i>=1; i--)
    {
        m=1;
        for(l=i;l<=n;l++){
            out<<a[l][m];
            m++;
        }
    }
    for(i=2;i<=n;i++)
    {
        m=i;
        for(l=1;l<=n-i+1;l++)
        {
            out<<a[l][m];
            m++;
        }
    }
    out<<'\n';
    for(j=1;j<=n;j++)
    {
        m=j;
        for(i=1;i<=j;i++)
        {
            out<<a[i][m];
            m--;
        }
    }
    for(i=2;i<=n;i++)
    {
        m=i;
        for(j=n;j>=i;j--)
        {
            out<<a[m][j];
            m++;
        }
    }
    return 0;
}
