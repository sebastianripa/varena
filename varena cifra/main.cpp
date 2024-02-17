#include <fstream>

using namespace std;

ifstream fin ("cifra.in");
ofstream fout ("cifra.out");

int main()
{
    int n, c, i;
    fin >> n >> c;
    for(i = c; i <= n; i += 9)
        fout << i << " ";
    return 0;
}
