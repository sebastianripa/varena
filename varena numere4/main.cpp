#include <fstream>

using namespace std;

ifstream fin ("numere4.in");
ofstream fout ("numere4.out");

long long prim (long long n)
{
    long long i;
    if(n < 2)
        return false;
    for(i = 1; i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

long long aproapePrim(int n)
{
    int i, j;
    if(prim(n))
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            break;
        if(prim(n/i))
            return false;
        for(j = 2; j*j <= n; j++)
        {
            if((n/i)%j == 0)
                break;
            if(prim(j) && prim(i) && prim(n/(i*j)) && i != j && j != n/(i*j) && i != n/(i*j))
                return true;
        }
    }
}

int main()
{
    long long n, x, i, nr3prim = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(descompNrFactoriPrimi(x) == 3)
            nr3prim++;
    }
    fout << nr3prim;
    return 0;
}
