#include <fstream>

using namespace std;

ifstream fin ("numere.in");
ofstream fout ("numere.out");


int vf[100000];

int NrDivizori(int n)
{
    int i, nd = 0;
    for(i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            nd++;
            if(n/i != i)
                nd++;
        }
    }
    return nd;
}

int main()
{
    int c, n, i, m = 0;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
    {
        vf[i] = NrDivizori(i);
        if(m < vf[i])
            m = vf[i];
    }
    for(i = 1; i <= n ; i++)
    {
        if(m == vf[i])
        {
            fout << i;
            break;
        }
    }
    return 0;
}
