#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pub.in");
ofstream fout ("pub.out");

int v[100005];

int main()
{
    int n, i, nrs = 0, n2, j, maxi = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    i = 1;
    while(i < n)
    {
        maxi = 0;
        if(v[i] == 0)
        {
            fout << -1;
            break;
        }
        n2 = i + v[i];
        if(n2 > n)
        {
            i = n+1;
            nrs++;
            break;
        }
        for(j = i + 1; j <= n2; j++)
        {
            if(maxi < v[j] + j)
            {
                maxi = v[j]+j;
                i = j;
            }
        }
        nrs++;
    }
    if(i >= n)
        fout << nrs;
    return 0;
}
