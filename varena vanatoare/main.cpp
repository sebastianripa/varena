#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("vanatoare.in");
ofstream fout ("vanatoare.out");

int main()
{
    unsigned long long sa, sn, nrr = 0, i, nrs = 0, a = 1, b = 2, c, nrsaf = 1, nrsnf = 0;
    fin >> sa >> sn;
    nrs = sa + sn;
    if(1 < sa)
    {
        nrr++;
        while(b <= nrs)
        {
            if(b%2 == 0)
                nrsaf += b/2;
            else
                nrsaf += b/2+1;
            nrsnf += b/2;
            if(nrsaf > sa)
                break;
            if(nrsnf > sn)
                break;
            nrr++;
            c = b;
            b += a;
            a = c;
        }
    }
    fout << nrr << '\n';
    if(nrr == 0)
        fout << 0 << '\n' << sn;
    else if(nrr == 1)
        fout << 1 << '\n' << sn;
    else
    {
        if(b%2 == 1)
            nrsaf -= b/2+1;
        else
            nrsaf -= b/2;
        nrsnf -= b/2;
        fout << sa - nrsaf << '\n' << sn - nrsnf;
    }
    return 0;
}
