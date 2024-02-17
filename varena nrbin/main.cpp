#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("nrbin.in");
ofstream fout ("nrbin.out");

int main()
{
    int n, i = 1, numbin = 0;
    fin >> n;
    while(i < n)
    {
        numbin++;
        if(i%2 == 0)
            i++;
        else
            i += 9;
    }
    fout << numbin;
    return 0;
}
