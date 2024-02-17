#include <fstream>

using namespace std;

ifstream fin ("cautare.in");
ofstream fout ("cautare.out");

char a[1000][1000], b[1000][1000];

int main()
{
    int n, m, i, j, ci, cj, i1 = 1, j1 = 1, nra = 0;
    char c;
    bool gheorghita = true;
    fin >> n >> m;
    fin.get(c);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin >> a[i][j];
    }
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= m; j++)
            fin >> b[i][j];
    }
    i = 1;
    j = 1;
    for(i = 1; i <= n-m+1; i++)
    {
        for(j = 1; j <= n-m+1; j++)
        {
            gheorghita = true;
            i1 = 1;
            for(ci = i; ci <= i+m-1; ci++)
            {
                j1 = 1;
                for(cj = j; cj <= j+m-1; cj++)
                {
                    if(a[ci][cj] != b[i1][j1])
                        gheorghita = false;
                    j1++;
                }
                i1++;
            }
            if(gheorghita)
                nra++;
        }
    }
    fout << nra;
    return 0;
}
