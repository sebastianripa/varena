#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cifre6.in");
ofstream fout ("cifre6.out");

long long b[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long c[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main()
{
    long long t, n, ans = 0;
    fin >> t >> n;
    if(t == 1)
    {
        while(n)
        {
            ans += b[n%10];
            n /= 10;
        }
        fout << ans;
    }
    else
    {
        ans = 1;
        while(n)
        {
            ans *= c[n%10];
            n /= 10;
        }
        fout << ans - 1;
    }
    return 0;
}
