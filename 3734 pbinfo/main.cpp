#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("formula1.in");
ofstream fout ("formula1.out");

int main()
{
    unsigned long long k, n, c, i, s = 0, nrm;
    fin >> c >> k >> n;
    if(c == 1)
        fout << (k*2-1)*(k*2-1);
    else
    {
        for(i = 1; i <= n; i++)
            s += ((i*2-1)*(i*2-1))/2;
        nrm = ((int)sqrt(2*s+1)+1)/2;
        fout << (nrm*2-1)*(nrm*2-1);
    }
    return 0;
}
