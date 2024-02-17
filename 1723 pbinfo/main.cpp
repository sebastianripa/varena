#include <bits/stdc++.h>

using namespace std;

ifstream fin ("culegere.in");
ofstream fout ("culegere.out");

int main()
{
    long long p, n, up, nr = 10, nrc = 0, i = 1;
    fin >> p >> n;
    if(p%2 == 1)
        up = p*(p/2+1);
    else
        up = p*p/2+p/2;
    do
    {
        nrc = nrc + (nr-nr/10)*i;
        nr *= 10;
        i += 1;
    }
    while(nr < up);
    nr /= 10;
    nrc = nrc + (up-nr+1)*i;
    fout << nrc << '\n';
    up = 1;
    for(i = 2; up < n; i++)
    {
        if(i%2 == 0)
            up = i*i/2+i/2;
        else
            up = i*(i/2+1);
    }
    fout << i-1;
    return 0;
}
