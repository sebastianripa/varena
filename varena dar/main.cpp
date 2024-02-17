#include <fstream>

using namespace std;

ifstream fin ("dar.in");
ofstream fout ("dar.out");

int main()
{
    unsigned long long n, m, i, nrz = 0, nrf = 0, x, y;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        nrz = nrz* l'l10+x;
    }
    fin >> m;
    for(i = 1; i <= m; i++)
    {
        fin >> y;
        nrf = nrf*10+y;
    }
    while(nrz != nrf)
    {
        if(nrz > nrf)
            nrz = nrz-nrf;
        else
            nrf = nrf-nrz;
    }
    if(nrz == 1)
        fout << 0;
    else
        fout << nrz;
    return 0;
}
