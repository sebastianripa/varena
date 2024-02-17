#include <fstream>

using namespace std;

ifstream fin ("cuburi.in");
ofstream fout ("cuburi2.out");

int v[1000001], vn[1000001];

int main()
{
    int n, x, i, nrl = 0, nrlm = 0, j, nrs, nrc, nr = 1;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        if(v[i+1] != v[i] && v[i+2] == v[i])
        {
            for(j = i+2; j <= n; j++)
            {
                v[j-1] = v[j];
                nrs = j-1;
                nrc = j;
            }
            for(j = 2; j <= n; j++)
            {
                if(v[j-1] == nrc && v[j] == nrc)
                    nrl++;
            }
            vn[nrc] = nrl;
            nr++;
        }
    }
    /*for(i = 1; i <= n; i++)
    {
        if(nrlm < v[i])
    }*/
    return 0;
}
