#include <fstream>

using namespace std;

ifstream fin ("comanda.in");
ofstream fout ("comanda.out");

int main()
{
    char c;
    int b, s = 0;
    fin >> b;
    while(fin >> c)
    {
        if(c != '$')
            s = s*b+(c - '0');
        else if(s != 0)
            b = s;
        s = 0;
    }
    fout << s;
    return 0;
}
