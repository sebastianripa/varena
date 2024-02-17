#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("bomboane1.in");
ofstream fout ("bomboane1.out");

int main()
{
    long long n = 0, nrb = 0, i, dm = 1;
    char c;
    do
    {
        fin.get(c);
        if(c != '$' && c != 10)
        {
            if(c >= '0' && c <= '9')
            {
                n = n*10 + (c - 48);
            }
            else
            {
                if(c == 'P')
                {
                    nrb += n;
                }
                else if(nrb >= n)
                {
                    nrb -= n;
                }
                n = 0;
            }
        }
    }
    while(c != 10);

    // gasesc divizorul maxim
    for(i = nrb/2; i >= 2; i--)
    {

        if(nrb%i == 0)
        {
            dm = i;
            break;
        }
    }
    fout << nrb << endl << nrb/dm;
    return 0;
}
