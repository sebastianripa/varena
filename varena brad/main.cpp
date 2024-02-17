#include <fstream>

using namespace std;

ifstream fin ("bradul.in");
ofstream fout ("bradul.out");

bool ePrim(int n)
{
    int d = 2;
    if(n < 2)
        return false;
    while(d*d <= n)
    {
        if(n%d == 0)
            return false;
        d++;
    }
    return true;
}

int main()
{
    int n, m, i, nrp = 0, s = 0, nr = 2, r = 1, mij;
    fin >> n >> m;
    for(i = m*(m-1)+1; i <= m*(m+1)-1; i++)
    {
        if(ePrim(i))
            nrp++;
    }
    while(s+nr <= n)
    {
        s += nr;
        r++;
        nr += 2;
    }
    if(s == n)
        fout << r-1 << " centru";
    else
    {
        mij = s+nr/2;
        if(n < mij)
            fout << r << " stang";
        else if(n > mij)
            fout << r << " drept";
        else if(n == mij)
            fout << r << " centru";
    }
    fout << '\n' << nrp;
    return 0;
}
