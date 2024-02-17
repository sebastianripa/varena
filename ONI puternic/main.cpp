#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("puternic.in");
ofstream fout ("puternic.out");

long long nrp = 0;

int v[500000000];

bool prim(int n)
{
    long long i;
    if(v[n] == 1)
        return true;
    if(v[n] == 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            v[n] = 2;
            return false;
        }
    }
    v[n] = 1;
    return true;
}

void puternic(int n)
{
    long long i;
    bool divizibil = true;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0 && (i%2 == 1 || i == 2))
        {
            if(prim(i))
            {
                if(n%(i*i) != 0)
                    divizibil = false;
            }
        }
    }
    if(prim(n))
        return;
    if(divizibil == true)
        nrp++;
    return;
}

int main()
{
    long long c, n, x, i;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        puternic(x);
    }
    fout << nrp;
    return 0;
}
