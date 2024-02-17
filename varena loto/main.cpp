#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("loto.in");
ofstream fout ("loto.out");

int v[7], vd[3] = {10000}, v1[1001], vf[10000];

int main()
{
    int n, x, i, j, d, nr1, nr2, aux;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v1[i];
    for(i = 1; i <= 6; i++)
    {
        fin >> v[i];
        vf[v[i]]++;
    }
    sort(v+1, v+6+1);
    aux = v[2];
    v[2] = v[6];
    v[6] = aux;
    vd[1] = 10000;
    vd[2] = 10000;
    for(i = 1; i <= 2; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(vf[v1[j]] == 0)
            {
                d = max(v[i], v1[j]) - min(v[i], v1[j]);
                if(vd[i] > d)
                {
                    vd[i] = d;
                    if(i == 1)
                        nr1 = v1[j];
                    else
                        nr2 = v1[j];
                }
                else if(vd[i] == d)
                {
                    if(i == 1)
                    {
                        if(v1[j] > nr1)
                            nr1 = v1[j];
                    }
                    else
                    {
                        if(v1[j] > nr2)
                            nr2 = v1[j];
                    }
                }
            }
        }
    }
    if(nr1 == nr2)
    {
        d = max(v[1], nr1) - min(v[1], nr1);
        j = max(v[2], nr2) - min(v[2], nr2);
        vd[1] = 10000;
        vd[2] = 10000;
        if(d < j)
        {
            for(i = 1; i <= n; i++)
            {
                if(vf[v1[i]] == 0)
                {
                    j = max(v[2], v1[i]) - min(v[2], v1[i]);
                    if(vd[2] > j && v1[i] != nr1)
                    {
                        vd[2] = j;
                        if(v1[i] != j)
                            nr2 = v1[i];
                    }
                    else if(vd[2] == j)
                    {
                        if(v1[i] > nr2)
                            nr2 = v1[i];
                    }
                }
            }
        }
        else
        {
            for(i = 1; i <= n; i++)
            {
                if(vf[v1[i]] == 0)
                {
                    d = max(v[1], v1[i]) - min(v[1], v1[i]);
                    if(vd[1] > d && v1[i] != nr2)
                    {
                            vd[1] = d;
                        if(v1[i] != j)
                            nr1 = v1[i];
                    }
                    else if(vd[1] == d)
                    {
                        if(v1[i] > nr1)
                            nr1 = v1[i];
                    }
                }
            }
        }
    }
    v[1] = nr1;
    v[2] = nr2;
    sort(v+1, v+6+1);
    for(i = 1; i <= 6; i++)
        fout << v[i] << ' ';
    return 0;
}
