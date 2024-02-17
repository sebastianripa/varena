#include <bits/stdc++.h>

using namespace std;

ifstream fin ("numere11.in");
ofstream fout ("numere11.out");

long long power(long long n)
{
    long long lap = 1;
    while(n--)
        lap *= 5;
    return lap;
}

int main()
{
    long long c, n, nrp, nri;
    cin >> c >> n;
    if(c == 1)
    {
        if(n == 3)
            fout << 9;
        else
        {
            nrp = 6*power(n - 3);
            nri = 3*power(n - 3);
            cout << nrp + nri;
        }
    }

    return 0;
}
