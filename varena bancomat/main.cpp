#include <fstream>

using namespace std;

ifstream fin ("bancomat.in");
ofstream fout ("bancomat.out");

int main()
{
    int n, x, i;
    long long s;
    fin >> s >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(x%10 == 2)
            s += x/10;
        else if(x%10 == 3 && x/10 < s)
            s -= x/10;
    }
    fout << s;
    return 0;
}
