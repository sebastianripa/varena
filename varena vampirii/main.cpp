#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("vampiri.in");
ofstream fout ("vampiri.out");

int main()
{
    char dir;
    int d = 0, s = 0, n, i, val;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> dir >> val;
        if(dir == 'D')
            d += val;
        else
            s += val;
    }
    if(d == s)
        fout << 0;
    else if(d > s)
        fout << 'D' << d - s;
    else
        fout << 'S' << s - d;
    return 0;
}
