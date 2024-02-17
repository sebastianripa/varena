#include <fstream>

using namespace std;

ifstream fin ("cifre3.in");
ofstream fout ("cifre3.out");

bool va[10];
bool vb[10];
int main()
{
    long long a, b, oga, ogb, i, nr = 0;
    bool aAfisat1 = false, aAfisat2 = false;
    fin >> a >> b;
    oga = a;
    ogb = b;
    while(a != 0)
    {
        va[a%10] = true;
        a /= 10;
    }
    while(b != 0)
    {
        vb[b%10] = true;
        b /= 10;
    }
    for(i = 0; i <= 9; i++)
    {
        if(va[i] && !vb[i])
        {
            fout << i << " ";
            aAfisat1 = true;
        }
    }
    if(!aAfisat1)
        fout << -1;
    fout << '\n';
    for(i = 9; i >= 0; i --)
    {
        if(va[i] && vb[i])
        {
            fout << i;
            aAfisat2 = true;
        }
    }
    if(!aAfisat2)
        fout << -1;
    return 0;
}
