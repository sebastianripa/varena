#include <fstream>

using namespace std;

ifstream fin ("joc20.in");
ofstream fout ("joc20.out");

int v[1001];

int main()
{
    int n, j, i, sa = 0, st = 0, ic = 1, sf;
    fin >> n;
    sf = n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        fin >> j;
        if(j == 1)
        {
            if(i%2 == 1)
                sa += v[ic];
            else
                st += v[ic];
            ic++;
        }
        else
        {
            if(i%2 == 1)
                sa += v[sf];
            else
                st += v[sf];
            sf--;
        }
    }
    if(sa > st)
        fout << sa << ' ' << 1;
    else if(st > sa)
        fout << st << ' ' << 2;
    else
        fout << sa << ' ' << 0;
    return 0;
}
