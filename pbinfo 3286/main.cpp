#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nrnot.in");
ofstream fout ("nrnot.out");

int v[1001];

int main()
{
    int n, x, i = 1, nr = 0, ogx = -1;
    fin >> n;
    while(fin >> x)
    {
        if(ogx != x)
            n--;
        ogx = x;
    }
    fout << n;
    return 0;
}
