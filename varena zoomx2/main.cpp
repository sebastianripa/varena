#include <fstream>

using namespace std;

ifstream fin ("zoomx2.in");
ofstream fout ("zoomx2.out");

char a[100][100];

int main()
{
    int n, i, n2, j, l = 1;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin >> a[i][j];
    }
    while(l <= n)
    {
        for(i = 1; i <= 2; i++)
        {
            for(j = 1; j <= n; j++)
                fout << a[l][j] << a[l][j];
            fout << '\n';
        }
        l++;
    }
    return 0;
}
