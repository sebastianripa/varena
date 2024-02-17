#include <fstream>

using namespace std;

ifstream fin ("panglica.in");
ofstream fout ("panglica.out");

int v[10001];

int main()
{
    int n, c, i, j, x, l = 1, lmax = 1, ci, cj;
    fin >> n >> c;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    for(i = 1; i < n; i++)
    {
        j = n;
        while(j > i && v[j] != v[i])
            j--;
        l = j-i+1;
        if(l > lmax)
        {
            lmax = l;
            ci = i;
        }
    }
    fout << lmax << '\n';
    fout << v[ci] << '\n';
    fout << ci - 1 << '\n';
    fout << n - (ci + lmax - 1);
    return 0;
}
