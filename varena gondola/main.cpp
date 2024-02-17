#include <fstream>

using namespace std;

ifstream fin ("gondola.in");
ofstream fout ("gondola.out");

int main()
{
    int n, x, i, p = 1, ogx, im = 0, dif = 0, ogdif = 0, dim = 0, difi = 0;
    long long s = 0;
    fin >> n;
    fin >> x;
    x += p;
    s += x;
    p++;
    for(i = 2; i <= n; i ++)
    {
        ogdif = dif;
        ogx = x;
        fin >> x;
        x += p;
        if(ogx >= x)
            dif = ogx - x;
        else
            dif = x - ogx;
        if(im < dif)
            im = dif;
        if(i != 2 && ogdif > dif)
            difi = ogdif - dif;
        else if(i != 2 && dif >= ogdif)
            difi = dif - ogdif;
        if(dim < difi)
            dim = difi;
        s += x;
        if(p == 3)
            p = 1;
        else
            p++;
    }
    fout << s << '\n' << im << '\n' << dim;
    return 0;
}
