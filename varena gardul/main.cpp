#include <fstream>

using namespace std;

ifstream fin ("gardul.in");
ofstream fout ("gardul.out");

int main()
{
    int n, p, q, nrn = 0, nrr = 0, nra = 0, nrv = 0, i, op, oq, pcmmmc, cmmmc;
    fin >> n >> p >> q;
    op = p;
    oq = q;
    while(op != oq)
    {
        if(op > oq)
            op = op - oq;
        else
            oq = oq - op;
    }
    cmmmc = (p*q)/op;
    pcmmmc = cmmmc;
    while(cmmmc <= n)
    {
        nrv++;
        cmmmc += pcmmmc;
    }
    fout << n - (n/p-nrv+n/q-nrv+nrv) << '\n';
    fout << n/p-nrv << '\n';
    fout << n/q-nrv << '\n';
    fout << nrv;
    return 0;
}
