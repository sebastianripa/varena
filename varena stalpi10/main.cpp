#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("stalpi10.in");
ofstream fout ("stalpi10.out");

long long v[2000005];

int main()
{
    long long n, i, j, x, y, mx = 0, my, nrm = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x >> y;
        for(j = x-y+1; j <= x+y; j++)
            v[j+1000000]++;
        if(mx < x)
        {
            mx = x;
            my = y;
        }
    }
    sort(v, v+mx+my+1+1000000, greater<long long>());
    fout << v[0] << " ";
    for(i = 0; v[i] == v[0]; i++)
        nrm++;
    fout << nrm << " ";
    nrm = 0;
    if(v[mx+my] == 0)
    {
        for(i = mx+my; v[i] == v[mx+my]; i--)
            nrm++;
        fout << nrm;
    }
    else
        fout << 0;
    return 0;
}
