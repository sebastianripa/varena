#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ruine.in");
ofstream fout ("ruine.out");

int v[100005], d[100005];

int main()
{
    int n, m, q, i, j, s = 0;
    char ts;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= m ;i++)
    {
        s = 0;
        fin >> ts >> q;
        if(ts == 'S')
            d[q] = 1;
        else
        {
            j = q + 1;
            while(d[j-1] != 1 && j <= n)
            {
                s += v[j];
                j++;
            }
            j = q - 1;
            while(d[j] != 1 && j >= 1)
            {
                s += v[j];
                j--;
            }
            fout << s + v[q] << '\n';
        }
    }
    return 0;
}
