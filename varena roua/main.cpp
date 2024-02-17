#include <fstream>

using namespace std;

ifstream fin ("roua.in");
ofstream fout ("roua.out");

char v[10001];

int main()
{
    int c, n, sr, nrsr = 0, i, j, f, nrr = 0, ok = 0;
    char cur;
    fin >> c >> n >> sr;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> cur;
            v[i] = cur;
        }
        f = sr;
        for(i = 1; f <= n; i++, f++)
        {
            for(j = i; j <= f; j++)
            {
                if(v[j] == 'r')
                    nrr++;
                else
                    ok++;
            }
            if(ok == 1)
                nrsr += 2;
        }
        fout << nrsr;
    }
    return 0;
}
