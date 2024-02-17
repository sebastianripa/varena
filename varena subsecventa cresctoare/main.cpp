#include <fstream>

using namespace std;

ifstream fin ("subcresc.in");
ofstream fout ("subcresc.out");

int main()
{
    int n, ogx, x, i, nre = 0, nrem = 0;
    fin >> n >> x;
    for(i = 2; i <= n; i++)
    {
        ogx = x;
        fin >> x;
        if(nre == 0 && ogx < x)
            nre = 2;
        else if(ogx < x)
            nre++;
        else
        {
            if(nrem < nre)
                nrem = nre;
            nre = 0;
        }
    }
    if(nrem < nre)
        nrem = nre;
    fout << nrem;
    return 0;
}
