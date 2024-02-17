#include <fstream>

using namespace std;

ifstream fin ("numere1.in");
ofstream fout ("numere1.out");

bool ePrim (int n)
{
    int i;
    if(n < 2)
        return false;
    else if(n == 2)
        return true;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool nrAproapePrim (int n)
{
    int i;
    if(ePrim(n))
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            break;
    }
    if(ePrim(i) && ePrim(n/i) && i != n/i)
            return true;
    return false;
}

int main()
{
    int n, x, i, nrap = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(nrAproapePrim(x))
            nrap++;
    }
    fout << nrap;
    return 0;
}
