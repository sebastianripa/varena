#include <fstream>

using namespace std;

ifstream fin ("oglinda.in");
ofstream fout ("oglinda.out");

int v[1000001], v1[500001], v2[500001];

int main()
{
    int n, m, i, j, t, k = 0;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        v[i] = i;
    while(m)
    {
        fin >> t;
        if(t == 1)
        {
            fin >> i >> j;
            k++;
            v1[k] = i;
            v2[k] = j;
        }
        else
        {
            fin >> i;
            fout << v[i] << '\n';
        }
        m--;
    }
    return 0;
}
