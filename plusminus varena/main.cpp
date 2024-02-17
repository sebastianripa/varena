#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("plusminus.in");
ofstream fout ("plusminus.out");

int main()
{
    int n;
    long long r = 0;
    char c = '+';
    do
    {
        fin >> n;

        if(c == '-')
        {
            r -= n;
        }
        else
        {
            r += n;
        }
        c = 0;
        fin.get(c);
        fin.get(c);
    }
    while(c != 0 && c != 10);
    fout << r;
    return 0;
}
