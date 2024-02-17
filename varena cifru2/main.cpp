#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cifru2.in");
ofstream fout ("cifru2.out");

int v[100001], c[10];

int main()
{
    int n, maxi = 0, x, y, i, j, s = 0, mini = 100000000, comb = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
        if(maxi < v[i])
            maxi = v[i];
    }
    fout << maxi << '\n';
    for(i = 0; i <= 9; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(v[j] < i)
            {
                x = i - v[j];
                y = v[j]+(9-i+1);
                c[i] += min(x, y);
            }
            else if(v[j] > i)
            {
                x = v[j] - i;
                y = i+(9-v[j]+1);
                c[i] += min(x, y);
            }
        }
        if(mini > c[i])
            mini = c[i];
    }
    fout << mini << '\n';
    for(i = 0; i <= 9; i++)
    {
        if(mini == c[i])
        {
            comb++;
            if(comb == 1)
                fout << i << '\n';
        }
    }
    fout << comb;
    return 0;
}
