#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("regele.in");
ofstream fout ("regele.out");


int main()
{
    int n, g, i, x, c, dif;
    fin >> n >> g;
    c = (n*(n+1)/2)*10;
    dif = c - g;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(x + dif == n)
        {
            fout << i;
        }
    }
    return 0;
}
