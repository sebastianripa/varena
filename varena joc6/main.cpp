#include <bits/stdc++.h>

using namespace std;

ifstream fin ("joc6.in");
ofstream fout ("joc6.out");

int vf[100005], v[100005];

int main()
{
    int n, k, p, i, j, nrz = 0, cnrz, x, s = 0, smj = 0, sm = 0, nrj, dif, juc, ck;
    fin >> n >> k >> p;
    ck = k;
    while(k--)
    {
        nrz = 0;
        s = 0;
        smj = 0;
        for(i = 1; i <= p; i++)
        {
            fin >> x;
            if(x == 0)
                nrz++;
            else
                v[i - nrz] = x;
        }
        sort(v+1, v+p-nrz+1);
        cnrz = nrz;
        for(i = 1; i <= p - nrz - 1; i++)
        {
            nrz = cnrz;
            s = v[i];
            for(j = i+1; j <= p - nrz; j++)
            {
                dif = v[j] - v[j-1];
                if(dif == 1)
                    s += v[j];
                else if(dif == 2)
                {
                    if(nrz >= dif - 1)
                    {
                        nrz--;
                        s += v[j];
                    }
                    else
                        break;
                }
                else if(dif == 3)
                {
                    if(nrz == dif - 1)
                    {
                        nrz -= 2;
                        s += v[j];
                    }
                    else
                        break;
                }
                else if(dif > 3)
                    break;
            }
            smj = max(smj, s);
        }
        if(sm < smj)
        {
            sm = smj;
            juc = ck - k;
        }
    }
    fout << juc << ' ' << sm;
    return 0;
}
