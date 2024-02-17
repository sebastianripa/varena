#include <bits/stdc++.h>

using namespace std;

ifstream fin ("2b1.in");
ofstream fout ("2b1.out");

long long pow(int n)
{
    long long p = 1;
    while(n--)
        p *= 2;
    return p;
}

int main()
{
    long long n, i, j, nr = 0, s = 0;
    fin >> n;
    for(i = 1; i <= 63; i++)
    {
        for(j = 0; j < i; j++)
        {
            nr = pow(i) + pow(j);
            if(nr > n)
                break;
            fout << nr << ' ';
        }
        if(nr > n)
            break;
    }
    return 0;
}
