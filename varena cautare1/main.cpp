#include <fstream>

using namespace std;

ifstream fin ("cautare1.in");
ofstream fout ("cautare1.out");

int v[100001], vp[100001];

int main()
{
    int m, n, nrp = 0, i, j, x;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= m; i++)
    {
        fin >> x;
        if(vp[x] != 0)
            fout << vp[x] << '\n';
        else
        {
            for(j = 1; j <= n; j++)
            {
                if(v[j] == x)
                {
                    nrp = j;
                    vp[x] = j;
                    break;
                }
            }
            fout << nrp << '\n';
            nrp = 0;
        }
    }
    return 0;
}
