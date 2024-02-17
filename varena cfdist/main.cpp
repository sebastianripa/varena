#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cfdist.in");
ofstream fout ("cfdist.out");

int main()
{
    long long n;
    int vf[10] = {0}, i, nrd = 0, c;

    // citire date
    fin >> n;

    // pregatire vector frecventa
    if (n == 0)
    {
        vf[0] = 1;
    }
    else
    {
        while(n != 0)
        {
            c = n%10;
            n = n/10;
            vf[c] = 1;
        }
    }

    // numarare cifre distincte
    for(i = 0; i < 10; i++)
    {
        nrd += vf[i];
    }

    // afisare date
    fout << nrd;
    return 0;
}
