#include <iostream>
#include <fstream>
#define NMax 2000001

using namespace std;

ifstream fin ("ciur.in");
ofstream fout ("ciur.out");

bool v[NMax];

int main()
{
    int n, d, i, nrp = 0;
    fin >> n;
    for(i = 2; i*i < NMax; i++)
        if(v[i] == 0)
            for(d = i*i; d < NMax; d += i)
                v[d] = 1;
    for(i = 2; i <= n; i++)
        if(v[i] == 0)
            nrp++;
    fout << nrp;
    return 0;
}
