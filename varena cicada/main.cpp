#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cicada.in");
ofstream fout ("cicada.out");

unsigned long long k = 0;

int main()
{
    long long n, cn, i;
    fin >> n;
    cn = n;
    k = n;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            k = k*(i-1)/i;
        while(n%i == 0)
            n /= i;
    }
    if(n != 1)
        k = k*(n-1)/n;
    k = cn - k - 1;
    fout << k*cn/2;
    return 0;
}
