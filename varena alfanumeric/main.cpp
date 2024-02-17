#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("alfanumeric.in");
ofstream fout ("alfanumeric.out");

int main()
{
    char c;
    long long n, i, s = 0;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin.get(c);
        fin.get(c);
        if(c >= 'a' && c <= 'z')
        {
            c -= 32;
            fout << c;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            fout << c;
        }
        else if(c >= '0' && c <= '9')
        {
            s += (c - 48);
        }
    }
    fout << endl;
    fout << s;
    return 0;
}
