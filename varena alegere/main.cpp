#include <fstream>

using namespace std;

ifstream fin ("alegere.in");
ofstream fout ("alegere.out");

bool v[100000];

int main()
{
    int n, k, i, nr = 2, nr2;
    fin >> n >> k;
    while(nr <= k)
    {
        for(i = nr; i <= n; i += nr)
        {
            if(v[i] == 0)
                v[i] = 1;
            else
            {
                v[i] = 0;
                nr2 = i;
            }
        }
        nr++;
    }
    nr = 0;
    for(i = 1; i <= n; i++)
    {
        if(v[i] == 0)
            nr++;
    }
    if(k != 2)
        fout << nr << " " << nr2;
    else
        fout << nr << " " << n;
    return 0;
}
