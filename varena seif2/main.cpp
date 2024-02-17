#include <fstream>

using namespace std;

ifstream fin ("seif2.in");
ofstream fout ("seif2.out");

int main()
{
    long long n, x, ogx, cx, c, cmax = 0, i, p = 1;
    fin >> n >> x;
    for(i = 2; i <= n; i++) {
        p = 1;
        ogx = x;
        fin >> x;
        cx = x;
        c = ogx;
        if(cx == 0)
            p = 10;
        while(cx)
        {
            p *= 10;
            cx /= 10;
        }
        c = c*p+x;
        if(cmax < c)
            cmax = c;
    }
    fout << cmax;
    return 0;
}
