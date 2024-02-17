#include <fstream>

using namespace std;

ifstream fin ("padure.in");
ofstream fout ("padure.out");

int main()
{
    long long n, ogx, x, nr = 0, nrm = 0, r, cx, cogx, i;
    fin >> n >> x;
    for(i = 2; i <= n; i++)
    {
        ogx = x;
        fin >> x;
        cx = x;
        cogx = ogx;
        while(cogx != 0)
        {
          r = cx%cogx;
          cx = cogx;
          cogx = r;
        }
        if(cx != 1)
        {
            if(nr == 0)
                nr += 2;
            else
                nr++;
        }
        else
        {
            if(nrm < nr)
                nrm = nr;
        }
    }
    fout << nrm;
    return 0;
}
