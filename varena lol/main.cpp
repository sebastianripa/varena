#include <fstream>

using namespace std;

ifstream fin ("lol.in");
ofstream fout ("lol.out");

int nrdiv(int n)
{
    long long i, nrd = 2;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            nrd++;
    }
    return nrd;
}

int main()
{
    long long n, x, y, i, nrdimp = 0, nrp = 0, ep;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x >> y;
        ep = (x+y)/2;
        fout << ep << '\n';
        if(nrdiv(ep)%2 == 1)
            nrdimp++;
        else if(nrdiv(ep) == 2 && ep != 0)
            nrp++;
    }
    fout << nrdimp << " " << nrp;
    return 0;
}
