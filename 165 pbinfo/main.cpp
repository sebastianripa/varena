#include <fstream>

using namespace std;

ifstream fin ("maxsim.in");
ofstream fout ("maxsim.out");

int v[1001];

int main()
{
    int n, s, sm, i1, j1, i, mij, j;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    mij = n/2+1;
    for(i = n, j = 1; i >= mij+1, j <= mij-1; i--, j++)
    {
        s = v[i] + v[j];
        if(sm < s)
        {
            sm = s;
            j1 = i;
            i1 = j;
        }
    }
    fout << sm << " " << i1 << " " << j1;
    return 0;
}
