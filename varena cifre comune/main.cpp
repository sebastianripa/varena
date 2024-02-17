#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cfcomune.in");
ofstream fout ("cfcomune.out");

int main()
{
    long long n, m;
    int vfn[10] = {0}, vfm[10] = {0}, i, cdc = 0;
    fin >> n >> m;
    while(n != 0)
    {
        vfn[n%10] = 1;
        n = n/10;
    }
    while(m != 0)
    {
        vfm[m%10] = 1;
        m = m/10;
    }
    for(i = 0; i < 10; i++)
    {
        if(vfn[i] + vfm[i] == 2)
        {
            cdc++;
        }
    }
    fout << cdc;
    return 0;
}
