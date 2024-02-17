#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("puteri2.in");
ofstream fout ("puteri2.out");

long long pow2(long long a, long long b)
{
    long long r = 1;
    while(b)
    {
        r = (r * a) % 1000000;
        b--;
    }
    return r % 100019;
}

int main()
{
    long long n, i, r = 0;
    fin >> n;
    long long a[n+1], b[n+1];

    for(i = 1; i <= n; i++)
        fin >> a[i];

    for(i = 1; i <= n; i++)
        fin >> b[i];

    for(i = 1; i <= n; i++)
    {
        r += pow2(a[i], b[i]);
        r %= 100019;
    }

    fout << r;
    return 0;
}
