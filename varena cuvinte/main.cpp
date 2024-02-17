#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cuvinte.in");
ofstream fout ("cuvinte.out");

int main()
{
    int nrcu = 0, v = 1;
    char c;
    do
    {
        fin.get(c);
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            v = 0;
        }
        else if(v == 0)
        {
            nrcu++;
            v = 1;
        }
    }
    while(c != 10);
    fout << nrcu;
    return 0;
}
