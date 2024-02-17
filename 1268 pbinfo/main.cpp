#include <fstream>

using namespace std;

ifstream fin ("easyquery.in");
ofstream fout ("easyquery.out");

long long v[100001], v2[100001], p1, p2, p;

int main()
{
    int n, q, t, i, j;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    fin >> q;
    for(i = 1; i <= q; i++)
    {
        fin >> t >> p1 >> p2 >> p;
        if(t == 2)
            p = p*(-1);
        v2[p1] += p;
        v2[p2 + 1] -= p;
    }
    for(i = 1; i <= n; i++)
        v2[i] = v2[i-1] + v2[i];
    for(i = 1; i <= n; i++)
        fout << v[i] + v2[i]<< ' ';
    return 0;
}
