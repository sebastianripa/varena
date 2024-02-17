#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("9div.in");
ofstream fout ("9div.out");

bool v[1000001];

int prim(int n)
{
    if(n <= 1)
        return 0;
    if(n == 2)
        return 1;
    for(int i = 3; i*i <= n; i += 2)
        if(n%i == 0)
            return 0;
    return 1;
}

int pow4(int n)
{
    n *= n;
    return n*n;
}

int pow8(int x)
{
    int x4 = (pow4(x));
    return x4*x4;
}

int div9(int n)
{
    int nr = 0;
    for(int p = 2; pow4(p) <= n; p++)
    {
        if(prim(p))
        {
            int p2 = p*p;
            for(int q = p+1; p2*q*q <= n; q++)
                nr += prim(q);
        }
    }
    for(int p = 2; pow8(p) <= n; p++)
        nr += prim(p);
    return nr;
}

int main()
{
    int n;
    fin >> n;
    fout << div9(n);
    return 0;
}
