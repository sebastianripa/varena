#include <fstream>

using namespace std;

ifstream fin ("inimioare.in");
ofstream fout ("inimioare.out");

int main()
{
    int n, a, b, x, y, c1, i, c2, c3, cmax1 = 0, ogcmax1, cmax2 = 0, ogcmax2, nra = 0, aux, c4;
    bool ok = false;
    fin >> n;
    for(i = 1; i <= n*2; i++)
    {
        fin >> a >> b >> x >> y;
        nra++;
        if(nra == n+1)
        {
            ok = true;
            nra = 0;
        }
        if(ok == false)
            ogcmax1 = cmax1;
        else
            ogcmax2 = cmax2;
        if(a > b)
            c1 = a*10+b;
        else
            c1 = b*10+a;
        if(b > x)
            c2 = b*10+x;
        else
            c2 = x*10+b;
        if(x > y)
            c3 = x*10+y;
        else
            c3 = y*10+x;
        if(a > y)
            c4 = a*10+y;
        else
            c4 = y*10+a;
        if(ok == false)
        {
            if(c1 >= c2 && c1 >= c3 && c1 >= c4)
                cmax1 = c1;
            else if(c2 >= c1 && c2 >= c3 && c2 >= c4)
                cmax1 = c2;
            else if(c3 >= c1 && c3 >= c2 && c3 >= c4)
                cmax1 = c3;
            else
                cmax1 = c4;
            if(ogcmax1 > cmax1)
            {
                aux = ogcmax1;
                ogcmax1 = cmax1;
                cmax1 = aux;
            }
        }
        else
        {
            if(c1 >= c2 && c1 >= c3 && c1 >= c4)
                cmax2 = c1;
            else if(c2 >= c1 && c2 >= c3 && c2 >= c4)
                cmax2 = c2;
            else if(c3 >= c1 && c3 >= c2 && c3 >= c4)
                cmax2 = c3;
            else
                cmax2 = c4;
            if(ogcmax2 > cmax2)
            {
                aux = ogcmax2;
                ogcmax2 = cmax2;
                cmax2 = aux;
            }
        }
    }
    if(cmax2 >= cmax1)
        fout << cmax2 << cmax1;
    else
        fout << cmax1 << cmax2;
    return 0;
}
