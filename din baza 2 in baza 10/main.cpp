#include <bits/stdc++.h>

using namespace std;

char v[100005];

ifstream fin ("baze.in");
ofstream fout ("baze.out");

void f(int n, int b2)
{
    int r;
    char c;
    if(n == 0)
        return;
    r = n%b2;
    if(r < 10)
        c = '0' + r;
    else
        c = 'A' + (r-10);

    f(n/b2, b2);
    fout << c;
}

int main()
{
    int b1, b2;
    long long n = 0;
    char c;

    fin >> b1 >> b2;

    while(fin >> c)
    {
        if(c - 48 < 10)
            n = n*b1 + (c - 48);
        else
            n = n*b1 + 10 + (c-'A');
    }
    if(n == 0)
        fout << 0;
    else
        f(n, b2);
    return 0;
}
