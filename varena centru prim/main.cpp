#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("centruprim.in");
ofstream fout ("centruprim.out");

bool ePrim(long long n)
{
    int d = 2;
    if(n < 2)
    {
        return 0;
    }
    while(d*d <= n)
    {
        if(n%d == 0)
        {
            return 0;
        }
        d++;
    }
    return 1;
}

int main()
{
    long long n, cn, p = 1;
    fin >> n;
    cn = n;
    while(cn != 0)
    {
        p = p*10;
        cn /= 10;
    }
    p /= 100;
    n /= 10;
    n %= p;
    if(ePrim(n))
    {
        fout << 1;
    }
    else
    {
        fout << 0;
    }
    return 0;
}
