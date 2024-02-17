#include <fstream>

using namespace std;

ifstream fin ("toate.in");
ofstream fout ("toate.out");

int main()
{
    int n, nr = 0, nrm = 0, inv = 0, i, x, cx, p = 1;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        p = 1;
        nr = 0;
        fin >> x;
        cx = x;
        while(cx)
        {
            p *= 10;
            cx /= 10;
        }
        p /= 10;
        while(p)
        {
            if(x/p%10 != 9)
                nr = nr*10 + x/p%10;
            p /= 10;
        }
        if(nrm < nr)
            nrm = nr;
    }
    fout << nrm;
    return 0;
}
