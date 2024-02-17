#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("antiterra.in");
ofstream fout ("antiterra.out");

int main()
{
    long long n, r = 0;
    char c, cc;
    do
    {
        fin >> n;
        fin.get(c);
        if(c == '+')
        {
            r += n;
            fin.get(c);
        }
        else if(c == '-')
        {
            r -= n;
            fin.get(c);
        }
        else
        {
            r += n;
        }
    }
    while(c != 10);
    fout << r;
    return 0;
}
