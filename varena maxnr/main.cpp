#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("maxnr.in");
ofstream fout ("maxnr.out");

int main()
{
    long long n, nr = 0, i, vf[10] = {0};
    fin >> n;
    while(n != 0)
    {
        vf[n%10]++;
        n /= 10;
    }
    for(i = 9; i >= 0; i--)
    {
        while(vf[i] > 0)
        {
            nr = nr*10 + i;
            vf[i]--;
        }
    }
    fout << nr;
    return 0;
}
