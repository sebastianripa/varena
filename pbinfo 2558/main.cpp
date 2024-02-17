#include <bits/stdc++.h>

using namespace std;

ifstream fin ("npe.in");
ofstream fout ("npe.out");

int main()
{
    long long n, i = 1, s = 0, in;
    fin >> n;
    while(s < n)
    {
        s = s + i*i;
        i++;
    }
    fout << i-1 << ' ';
    in = s - i*i + 1;

    return 0;
}
