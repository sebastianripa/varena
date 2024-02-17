#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("ploaie.in");
ofstream fout ("ploaie.out");

char v[2000003];

int main()
{
    int n, i, nr = 0, pp, j;
    fin >> n;
    v[2] = 0;
    for(i = 2; i < 2000003; i++)
    {
        if(v[i] == 0)
        {
            for(j = i*2; j < 2000003; j += i)
                v[j] = 1;
        }
    }
    for(i = 2; i < 2000003; i++)
    {
        if(v[i] == 0)
        {
            j = i;
            j++;
            while(v[j] == 1)
                j++;
            if(sqrt(i+j) == (int)sqrt(i+j))
            {
                pp = i+j;
                nr++;
            }
            if(nr == n)
            {
                fout << pp;
                break;
            }
        }
    }
    return 0;
}
