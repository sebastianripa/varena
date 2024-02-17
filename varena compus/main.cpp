#include <fstream>

using namespace std;

ifstream fin ("compus.in");
ofstream fout ("compus.out");

int main()
{
    bool found = false;
    int n, e, p, c, i, j, aux;
    fin >> n >> e >> p;
    int v[n];
    for(i = 0; i < n; i++)
        fin >> v[i];

    for(i = 0; i < n; i++)
    {
        if(v[i] == e)
            found = true;
        if(found == true && i < n - 1)
            v[i] = v[i + 1];
    }
    for(i = n - 1; i > p; i--)
        v[i] = v[i - 1];
    v[p] = e;
    for(i = 0; i < n/2; i++)
    {
        aux = v[i];
        v[i] = v[n - (i + 1)];
        v[n - (i + 1)] = aux;
    }
    aux = v[0];
    for(i = 1; i < n; i++)
        v[i - 1] = v[i];
    v[n - 1] = aux;

    for(i = 0; i < n; i++)
        fout << v[i] << " ";
    return 0;
}
