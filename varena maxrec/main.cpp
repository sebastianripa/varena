#include <bits/stdc++.h>

using namespace std;

ifstream fin ("maxrec.in");
ofstream fout ("maxrec.out");

long long n, x, maxi, um, pn;

void maxim()
{
    maxi = -2000000001;
    if(pn > n)
        maxi = um;
    fin >> x;
    if(n > 1)
    {
        if(maxi < x)
        {
            maxi = x;
            um = maxi;
        }
        n--;
        maxim();
    }
    else
    {
        if(maxi < x)
            maxi = x;
        return;
    }
}

int main()
{
    fin >> n;
    pn = n;
    maxim();
    fout << maxi;
    return 0;
}
