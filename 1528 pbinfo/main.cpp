#include <bits/stdc++.h>

using namespace std;

ifstream fin ("operatiimatematice.in");
ofstream fout ("operatiimatematice.out");

int main()
{
    int n, s, nr = 0, i, x;
    fin >> n >> s;
    nr = nr*10+s;
    for(i = 2; i <= n; i++)
    {
        fin >> x;
        s *= 3;
        s += x;
        if(i != n)
            s -= ((s/7)*7);
        nr = nr*10+x;
    }
    fout << s << '\n';
    if(nr%7 == 0)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}
