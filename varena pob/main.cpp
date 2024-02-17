#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pob.in");
ofstream fout ("pob.out");

int v[100005], b[100005];

int main()
{
    int n, i, nrs = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    i = 1;
    while(i < n && b[i] == 0)
    {
        b[i] = 1;
        if(i < v[i] && i + v[i] <= n)
            i += v[i];
        else if(i > v[i] && i - v[i] >= 1)
            i -= v[i];
        nrs++;
    }
    if(i == n)
        fout << nrs;
    else
        fout << -1;
    return 0;
}
