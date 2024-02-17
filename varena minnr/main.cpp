#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("minnr.in");
ofstream fout ("minnr.out");

int main()
{
    long long n, nr = 0;
    int vf[10] = {0}, i;
    fin >> n;

    while(n != 0)
    {
        vf[n%10]++;
        n = n/10;
    }

    for(i = 1; i < 10; i++)
    {
        while(vf[i] > 0)
        {
            nr = nr*10 + i;

            while(vf[0] > 0)
            {
                nr = nr*10;
                vf[0]--;
            }
            vf[i]--;
        }
    }
    fout << nr;
    return 0;
}
