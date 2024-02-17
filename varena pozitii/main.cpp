#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("pozitii.in");
ofstream fout ("pozitii.out");

int main()
{
    long long n, x, i, nrecpl = 0;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        if(x == i)
        {
            nrecpl++;
        }
    }
    fout << nrecpl;
    return 0;
}
