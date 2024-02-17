#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ucif.in");
ofstream fout ("ucif.out");

int main()
{
    int s = 0, p, n, i, j;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        p = 1;
        for(j = 0; j < i; j++)
        {
            p *= i%10;
            p %= 10;
        }
        s += p%10;
    }
    fout << s%10;
    return 0;
}
