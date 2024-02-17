#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nrsufix.in");
ofstream fout ("nrsufix.out");

int main()
{
    long long n, cn, p10n = 1, x, ans = -1;
    fin >> n;
    cn = n;
    while(n)
    {
        p10n *= 10;
        n /= 10;
    }
    n = cn;
    while(fin >> x)
    {
        if(x%p10n == n)
            ans = x;
    }
    if(ans == -1)
        fout << "nu exista";
    else
        fout << ans;
    return 0;
}
