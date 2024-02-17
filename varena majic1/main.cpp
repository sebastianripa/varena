#include <fstream>

using namespace std;

ifstream fin ("magic1.in");
ofstream fout ("magic1.out");

int v[10000];

int main()
{
    int n, i;
    char c, nrm = ':';
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> c;
        if(c >= '0' && c <= '9')
        {
            if(nrm > c && c != '0')
                nrm = c;
            v[c-48] = 1;
        }
        else
        {
            c -= 32;
            fout << c;
        }
    }
    fout << '\n';
    fout << nrm;
    v[nrm-48] = 0;
    if(v[0] == 1)
        fout << 0;
    for(i = 1; i <= 10; i++)
    {
        if(v[i] != 0)
            fout << i;
    }
    return 0;
}
