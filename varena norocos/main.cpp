#include <fstream>

using namespace std;

ifstream fin ("norocos.in");
ofstream fout ("norocos.out");

int nrm = 0;

int nrfactoridescompprim(int n)
{
    int i = 2, nrdp = 0, nrp = 0, cn;
    nrm = 0;
    while(n != 1)
    {
        nrp = 0;
        while(n%i == 0)
        {
            nrp++;
            n /= i;
        }
        if(i*i > n)
        {
            cn = n;
            n /= n;
            nrdp++;
        }
        if(nrp > 0)
            nrm++;
        if(nrp == 1)
            nrdp++;
        i++;
    }
    return nrdp;
}

int main()
{
    long long c, n, k, x, nrmin = 2000000001, nrmax = 0, i, nrkn = 0, nr;
    fin >> c >> n >> k;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(c == 1)
        {
            if(x%2 == 1 && nrmin > x)
                nrmin = x;
            if(x%2 == 1 && nrmax < x)
                nrmax = x;
        }
        else
        {
            nr = nrfactoridescompprim(x);
            if(nr == k && nr == nrm+1)
                nrkn++;
        }
    }
    if(c == 1)
        if(nrmax == 0)
            fout << 0;
        else
            fout << nrmin << " " << nrmax;
    else
        fout << nrkn;
    return 0;
}
