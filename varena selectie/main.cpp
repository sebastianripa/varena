#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("selectie.in");
ofstream fout ("selectie.out");

int v[1000001];
int n, k, i;

int main()
{
    fin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    nth_element(v+1, v+k, v+n+1);
    fout << v[k];
    return 0;
}
