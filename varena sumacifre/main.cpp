#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

ifstream fin ("sumacifre.in");
ofstream fout ("sumacifre.out");

int main()
{
    int n, i, s = 0;
    char c;
    fin >> n;
    fin.get(c);
    for(i = 1; i <= n; i++)
    {
        fin.get(c);
        if(isdigit(c))
            s += c - '0';
    }
    fout << s;
    return 0;
}
