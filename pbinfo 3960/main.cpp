#include <bits/stdc++.h>

using namespace std;

ifstream fin ("intersectie.in");
ofstream fout ("intersectie.out");

long long v[100005], d[100005];

int main()
{
    unsigned int i = 1, n = 1, s = 1, n2;
    bool exista = false, e = false;
    while(n != 0)
    {
        fin >>  n;
        v[s] = n;
        d[s++] = n;
    }
    s -= 2;
    while(fin >> n)
    {
        if(n == 0)
        {
            while(n2 < v[s])
                d[s--] = 0;
            i = 1;
        }
        while(n > v[i])
            d[i++] = 0;
        if(n == v[i])
            i++;
        n2 = n;
    }
    for(i = 1; i <= s; i++)
    {
        if(d[i] != 0)
        {
            fout << v[i] << ' ';
            exista = true;
        }
    }
    if(!exista)
        fout << "nu exista";
    return 0;
}
