#include <bits/stdc++.h>

using namespace std;

ifstream fin ("veverite.in");
ofstream fout ("veverite.out");

long long v[100005];

int main()
{
    long long n, q, i, j = 1, s, r = 0;
    fin >> n >> q;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= q; i++)
    {
        j = 1;
        r = 0;
        fin >> s;
        if(s < v[1])
        {
            if(i == q)
                fout << -1;
            else
                fout << -1 << ' ';
            continue;
        }
        if(s >= v[n])
        {
            if(i == q)
                fout << 0;
            else
                fout << 0 << ' ';
            continue;
        }
        while(j <= n-1)
        {
            if(s < v[j+1])
            {
                s += v[j];
                r++;
            }
            if(s >= v[n])
            {
                if(i == q)
                    fout << r;
                else
                    fout << r << ' ';
                break;
            }
            j++;
        }
    }
    return 0;
}
