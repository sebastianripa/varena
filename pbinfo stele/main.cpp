#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("stele.in");
ofstream fout ("stele.out");

int main()
{
    long long c, n, i, j, nr;
    fin >> c >> n;
    fout << c*(c-1)+1 << '\n';
    nr = n;
    while(sqrt(nr) != (int)sqrt(nr))
        nr++;
    fout << sqrt(nr) << ' ' << nr - n + 1;
    return 0;
}
