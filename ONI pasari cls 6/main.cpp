#include <fstream>

using namespace std;

ifstream fin ("pasari.in");
ofstream fout ("pasari.out");

int a[1000][1000];

int main()
{
    int c, n, l, i, j, nrmps = 0, nrps = 0  , poz;
    fin >> c >> n >> l;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            fin >> a[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        nrps = 0;
        for(j = l; j <= n; j++)
        {
            if(a[j][i] <= a[l][i])
                nrps++;
            else
                break;
        }
        for(j = l-1; j >= 1; j--)
        {
            if(a[j][i] <= a[l][i])
                nrps++;
            else
                break;
        }
        for(j = i; j <= n; j++)
        {
            if(a[l][j] <= a[l][i])
                nrps++;
            else
                break;
        }
        for(j = i-1; j >= 1; j--)
        {
            if(a[l][j] <= a[l][i])
                nrps++;
            else
                break;
        }
        nrps--;
        if(nrps == n*2)
        {
            nrmps = i;
            break;
        }
        if(nrps > nrmps)
        {
            nrmps = nrps;
            poz = i;
        }
    }
    fout << poz;
    return 0;
}
