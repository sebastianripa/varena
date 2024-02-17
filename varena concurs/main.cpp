#include <fstream>

using namespace std;

ifstream fin ("concurs.in");
ofstream fout ("concurs.out");

int main()
{
    int e, n, x, nrpo = 0, nrps = 0, i;
    bool ok = false;
    fin >> e >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(e == x)
        {
            fout << "DA" << '\n';
            ok = true;
        }
        if(x/100 == e/100)
            nrpo++;
        if(x/10 == e/10)
            nrps++;
    }
    if(!ok)
        fout << "NU" << '\n';
    fout << nrpo << '\n' << nrps;
    return 0;
}
