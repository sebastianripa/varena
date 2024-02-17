#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("numchar.in");
ofstream fout ("numchar.out");

int main()
{
    int n, i, nrc = 0, nrl = 0;
    char c;
    fin >> n;
    fin.get(c);
    for(i = 1; i <= n; i++)
    {
        fin.get(c);
        if(c >= '0' && c <= '9')
        {
            nrc++;
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            nrl++;
        }
    }
    fout << nrl << " " << nrc;
    return 0;
}
