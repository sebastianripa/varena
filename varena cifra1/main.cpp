#include <fstream>

using namespace std;

ifstream fin ("cifra1.in");
ofstream fout ("cifra1.out");

int main()
{
    long long n, c, p2 = 10, j2, nrmin = 1000000000000, cn, n2;
    fin >> n >> c;
    cn = n;
    while(n2)
    {
        j2 = n%p2;
        n /= p2;
        n2 = n;
        n = n*10+c;
        n = n*p2+j2;
        if(nrmin > n)
            nrmin = n;
        n = cn;
        p2 *= 10;
    }
    if(n*10+c < nrmin)
        nrmin = n*10+c;
    fout << nrmin;
    return 0;
}
