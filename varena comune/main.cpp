#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("comune.in");
ofstream fout ("comune.out");

int main()
{
    long long a, b, nrcc = 0, c, nc, cb;
    fin >> a >> b;
    while(a != 0)
    {
        c = a%10;
        nc = 1;
        cb = b;
        while(b != 0)
        {
            if(b%10 == c)
            {
                nrcc++;
                b /= 10;
                cb = cb % nc;
                cb += b * nc;
                break;
            }
            else
            {
                nc *= 10;
            }
            b /= 10;
        }
        b = cb;
        a /= 10;
    }
    fout << nrcc;
    return 0;
}
