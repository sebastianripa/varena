#include <fstream>

using namespace std;

ifstream fin ("ksir.in");
ofstream fout ("ksir.out");

int main()
{
    int n, nres =  1, nret = 1, g, i, v1;
    fin >> n;
    while(nret < n)
    {
        nret += nres*2+1;
        nres++;
    }
    v1 = nret - nres+1;
    if(v1 <= n && n <= nret)
        fout << g;
    else
    {
        n = n - (nres-1)*(nres-1);
        fout << n;
    }
    return 0;
}
