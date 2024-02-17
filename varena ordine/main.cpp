#include <fstream>

using namespace std;

ifstream fin ("ordine.in");
ofstream fout ("ordine.out");

long long v[250001], v2[250001];

int main()
{
    long long n, c, i, nr = 1, cn;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    fin >> c;
    cn = n;
    if(c == 1)
    {
        if(n%2 == 0)
            fout << v[n];
        else
            fout << v[n/2+1];
    }
    else
    {
        while(v[1] != 0)
        {
            if(n%2 == 1)
            {
                v2[n] = v[n/2+1];
                n--;
                v[n/2+1] = 0;
            }
            else
            {
                if(n == cn)
                    nr = 0;
                v2[n] = v[n+nr];
                v[n+nr] = 0;
                n--;
                nr++;
            }
        }
        for(i = 1; i <= cn; i++)
            fout << v2[i] << " ";
    }
    return 0;
}
