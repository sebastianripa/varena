#include <fstream>

using namespace std;

ifstream fin ("chipsidale.in");
ofstream fout ("chipsidale.out");

int v[1000];

int main()
{
    int n, i, nrsc = 0, nrac = 0, cn;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    while(n > 2)
    {
        i = 1;
        cn = n;
        if(n%2 == 0)
        {
            while(n > cn/2)
            {
                v[i] += v[n];
                v[n] = 0;
                n--;
                i++;
            }
            nrac += v[n];
            nrsc++;
            n--;
        }
        else
        {
            while(n > cn/2+1)
            {
                v[i] += v[n];
                n--;
                i++;
            }
            nrac += v[n];
            nrsc++;
            n--;
        }
    }
    fout << nrsc << " ";
    fout << nrac << '\n';
    if(n == 1)
    {
        fout << 1 << " ";
        fout << v[1];
    }
    else
    {
        fout << 2 << " ";
        fout << v[1] + v[2
        ];
    }
    return 0;
}
