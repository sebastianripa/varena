#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("miny.in");
ofstream fout ("miny.out");

int main()
{
    int n, x, p = 1, i;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        p *= x;
        p %= 100;
    }
    fout << p/10;
    return 0;
}
