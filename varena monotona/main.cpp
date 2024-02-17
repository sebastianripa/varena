#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("monotona.in");
ofstream fout ("monotona.out");

int main()
{
    long long n, x, oldx, i, crescator = 1, descrescator = 1;
    fin >> n;
    fin >> x;
    for(i = 2; i <= n; i++)
    {
        oldx = x;
        fin >> x;
        if(oldx < x)
            crescator++;
        else if(oldx > x)
            descrescator++;
        else
        {
            crescator++;
            descrescator++;
        }
    }
    if(crescator == n || descrescator == n)
        fout << "da";
    else
        fout << "nu";
    return 0;
}
