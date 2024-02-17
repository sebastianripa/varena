#include <bits/stdc++.h>

using namespace std;

ifstream fin ("parale.in");
ofstream fout ("parale.out");

int v[200001];

int main()
{
    int n, m, i, j, a, x = 0;
    fin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        fin >> a;
        for(j = a; j <= n*2; j += a)
            v[j] = 1;
    }
    for(i = 2; i <= n*2; i++)
    {
        if(v[i] == 0)
        {
            if(i <= n)
                x += i-1;
            else if(i >= n+1)
                x += (2*n) - i + 1;
        }
    }
    fout << x;
    return 0;
}
