#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ograda.in");
ofstream fout ("ograda.out");

int nrdi, nrdp;

void divpi(int n, int m)
{
    int i;
    for(i = 1; i <= n/2; i++)
    {
        if(n%i == 0)
        {
            if(i%2 == 1)
                nrdi++;
        }
    }
    if(n%2 == 1)
        nrdi++;
    for(i = 1; i <= m/2; i++)
    {
        if(m%i == 0)
        {
            if(i%2 == 0)
                nrdp++;
        }
    }
    if(m%2 == 0)
        nrdp++;
}

int main()
{
    unsigned long long t, p, c, v, g;
    fin >> t >> c >> p;
    if(t == 1)
    {
        v = (p - 2*c)/2;
        g = c - v;
        fout << g << ' ' << v;
    }
    else
    {
        divpi(c, p);
        fout << nrdi  << ' ' << nrdp;
    }
    return 0;
}
