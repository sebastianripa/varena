#include <fstream>

using namespace std;

ifstream fin ("rotk.in");
ofstream fout ("rotk.out");

int v1[200000], v2[200000];

int main()
{
    int n1, n2, k, k1, k2, aux, i, j;
    fin >> n1;
    for(i = 1; i <= n1; i++)
        fin >> v1[i];
    fin >> k1 >> n2;
    for(i = 1; i <= n2; i++)
        fin >> v2[i];
    fin >> k2 >> k;
    for(i = 1; i <= k1; i++)
    {
        aux = v1[n1];
        v1[n1] = v1[1];
        for(j = 1; j <= n1-2; j++)
            v1[j] = v1[j+1];
        v1[n1-1] = aux;
    }
    for(i = 1; i <= k2; i++)
    {
        aux = v2[n2];
        v2[n2] = v2[1];
        for(j = 1; j <= n2-2; j++)
            v2[j] = v2[j+1];
        v2[n2-1] = aux;
    }
    j = n1+1;
    for(i = 1; i <= n2; i++)
    {
        v1[j] = v2[i];
        j++;
    }
    n1 += n2;
    for(i = 1; i <= k; i++)
    {
        aux = v1[n1];
        v1[n1] = v1[1];
        for(j = 1; j <= n1-2; j++)
            v1[j] = v1[j+1];
        v1[n1-1] = aux;
    }
    for(i = 1; i <= n1; i++)
        fout << v1[i] << " ";
    return 0;
}
