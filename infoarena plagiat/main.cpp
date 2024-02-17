#include <bits/stdc++.h>

using namespace std;

ifstream fin ("plagiat.in");
ofstream fout ("plagiat.out");

void rez()
{
    int n, i, j, dif, dif1, r = 0;
    fin >> n;
    map<pair<int, int>, int> f;
    pair<int, int> v[401];
    dif = 0;
    dif1 = 0;
    for(i = 1; i <= n; i++)
        fin >> v[i].first >> v[i].second;
    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j <= n; j++)
        {
            dif = max(v[i].first, v[j].first) - min(v[i].first, v[j].first);
            dif1 = max(v[i].second, v[j].second) - min(v[i].second, v[j].second);
            if(++f[{dif, dif1}] == 3)
                r = 1;
        }
    }
    if(r == 1)
        fout << "DA" << '\n';
    else
        fout << "NU" << '\n';
    return;
}

int main()
{
    int t, i;
    fin >> t;
    for(i = 1; i <= t; i++)
        rez();
    return 0;
}
