#include <fstream>

using namespace std;

ifstream fin ("cifra2.in");
ofstream fout ("cifra2.out");

int v[10];

int inv(int n)
{
    int inv = 0;
    while(n)
    {
        inv = inv*10 + n%10;
        n /= 10;
    }
    return inv;
}

int main()
{
    int n, k = 0, c, cn, cmin, i;
    fin >> n;
    while(n > 9)
    {
        c = 0;
        v[8] = {0};
        cmin = 10;
        k++;
        cn = n;
        while(cn)
        {
           if(cmin > cn%10)
                cmin = cn%10;
           cn /= 10;
        }
        while(n)
        {
            if(n%10 != cmin)
            {
                c++;
                v[c] = n%10;
            }
            n /= 10;
        }
        for(i = 1; i <= c; i++)
        {
            v[i] -= cmin;
            n = n*10 + v[i];
        }
        n = inv(n);
        if(k == 1)
            fout << cmin << '\n' << n << '\n';
    }
    fout << n;
    return 0;
}
