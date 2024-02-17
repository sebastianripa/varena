#include <fstream>

using namespace std;

ifstream fin ("matrixdel.in");
ofstream fout ("matrixdel.out");

int a[100][100], vi[100], vj[100];

int main()
{
    int n, m, p, l, i, j, x;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            fin >> a[i][j];
    }
    fin >> p;
    for(i = 1; i <= p; i++)
    {
        fin >> x;
        vi[x] = 1;
    }
    fin >> l;
    for(i = 1; i <= l; i++)
    {
        fin >> x;
        vj[x] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        if(!vi[i])
        {
            for(j = 1; j <= m; j++)
            {
                if(!vj[j])
                    fout << a[i][j] << " ";
            }
            fout << '\n';
        }
    }
    return 0;
}
