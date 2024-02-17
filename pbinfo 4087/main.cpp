#include <bits/stdc++.h>

using namespace std;

ifstream fin ("vecine.in");
ofstream fout ("vecine.out");

int main()
{
    int c, n, x, ogx, i, r = 0;
    fin >> c >> n;
    if(c == 1)
    {
        fin >> x;
        for(i = 2; i <= n; i++)
        {
            ogx = x;
            fin >> x;
            if(x == ogx + 1)
                r++;
        }
        fout << r;
    }
    return 0;
}
