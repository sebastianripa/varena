#include <fstream>

using namespace std;

ifstream fin ("martisoare.in");
ofstream fout ("martisoare.out");

int v[100001], cif1, cif2;

void cifGresite(int nrg, int primu)
{
    while(nrg)
    {
        if(nrg%10 != primu%10)
        {
            if(cif1 == 0)
                cif1 = nrg%10;
            else
                cif2 = nrg%10;
        }
        nrg /= 10;
        primu /= 10;
    }
}

int main()
{
    int n, primu, i;
    fin >> n;
    for(i = 1; i <= n; i++) {
        fin >> v[i];
        if(i > 1 && v[i] - v[i-1] == 1)
            primu = v[i] - i + 1;
    }
    for(i = 1; i <= n; i++) {
        if(v[i] != primu + i - 1 && (cif1 == 0 || cif2 == 0))
            cifGresite(v[i], primu + i - 1);
    }
    fout << min(cif1, cif2) << ' ' << max(cif1, cif2) << '\n' << primu + n - 1;
    return 0;
}
