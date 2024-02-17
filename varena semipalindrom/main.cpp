#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("semipalindrom.in");
ofstream fout ("semipalindrom.out");

int main()
{
    int n, cn, nc = 0, i, p1 = 1, p2 = 1, j2, j = 0;
    fin >> n;
    cn = n;
    while(cn != 0)
    {
        cn = cn/10;
        nc++;
    }
    for(i = 1; i <= nc/2; i++)
    {
       j += n%10*p1;
       p1 *= 10;
       n /= 10;
    }
    if(nc%2 > 0)
        n = n/10;
    if(n == j)
        fout << j;
    else
        fout << n*10/p1;
    return 0;
}
