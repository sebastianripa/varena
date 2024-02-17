#include <fstream>

using namespace std;

ifstream fin ("matrix.in");
ofstream fout ("matrix.out");

int a[100][100];

int main()
{
    int n, m, i, j, aux;
    char c1, c2;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            fin >> a[i][j];
    }
    fin.get(c1);
    while(fin.get(c1) && fin.get(c2))
    {
        if(c1 == 'F' && c2 == 'H')
        {
            for(i = 1; i <= n/2; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    aux = a[i][j];
                    a[i][j] = a[n-i+1][j];
                    a[n-i+1][j] = aux;
                }
            }
        }
        else if(c1 == 'F' && c2 == 'V')
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m/2; j++)
                {
                    aux = a[i][j];
                    a[i][j] = a[i][m-j+1];
                    a[i][m-j+1] = aux;
                }
            }
        }
        else if(c1 == 'R' && c2 == 'H')
        {
            for(i = 1; i <= n; i++)
            {
                aux = a[i][m];
                for(j = m; j >= 1; j--)
                {
                    if(j == 1)
                        a[i][j] = aux;
                    else
                        a[i][j] = a[i][j-1];
                }
            }
        }
        else
        {
            for(j = 1; j <= m; j++)
            {
                aux = a[n][j];
                for(i = n; i >= 1; i--)
                {
                    if(i == 1)
                        a[i][j] = aux;
                    else
                        a[i][j] = a[i-1][j];
                }
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
    return 0;
}
