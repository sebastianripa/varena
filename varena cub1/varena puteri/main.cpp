#include <fstream>

using namespace std;

ifstream fin ("puteri.in");
ofstream fout ("puteri.out");

int main()
{
    long long n, nd0 = 0, nrp = 1;
    fin >> n;
    while(nrp <= n)
    {
        nd0++;
        nrp *= 2;
    }
    fout << nd0 << '\n';
    nrp /= 2;
    if(nrp == n)
        nrp /= 2;
    fout << nrp + 1;
    return 0;
}
