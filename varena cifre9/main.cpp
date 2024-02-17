#include <fstream>

using namespace std;

ifstream fin ("cifre9.in");
ofstream fout ("cifre9.out");

long long invers(long long n)
{
    int inv = 0;
    while(n)
    {
        inv = inv*10+n%10;
        n /= 10;
    }
    return inv;
}

int main()
{
    long long n, c, nrac = 0, cn = 0, i, inv = 0;
    fin >> n >> c;
    cn = n;
    while(cn)
    {
        if(cn%10 == c)
            nrac++;
        cn /= 10;
    }
    fout << nrac << '\n';
    if(c != 0)
    {
        for(i = 1; i <= nrac; i++)
            fout << c;
    }
    while(n)
    {
        if(n%10 != c)
            inv = inv*10+n%10;
        n /= 10;
    }
    inv = invers(inv);
    fout << inv;
    return 0;
}
