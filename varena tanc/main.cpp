#include <bits/stdc++.h>

using namespace std;

ifstream fin ("tanc.in");
ofstream fout ("tanc.out");

char m[1005][105];
int t[205][205];

int main()
{
    int cer, nrs, ls, lt, it, i = 1, j, l, poz1 = 1, poz2 = 1, s = 1, cpoz1, cpoz2;
    char c, ogc;
    bool ok = false;
    fin >> cer >> nrs >> ls >> lt >> it;
    fin.get();
    for(l = 1; l <= nrs; l++)
    {
        for(i; i <= ls*l; i++)
        {
            for(j = 1; j <= ls; j++)
                fin.get(m[i][j]);
            fin.get();
        }
    }
    if(cer == 1 || cer == 2)
    {
        fin.get(c);
        while(c != '\n')
        {
            if(c == 'S')
                poz1 += ls;
            if(c == 'V')
                poz2 -= ls;
            if(c == 'N')
                poz1 -= ls;
            if(c == 'E')
                poz2 += ls;
            s++;
            if(s > nrs)
                s = 1;
            ogc = c;
            fin.get(c);
        }
        if(cer == 1)
            fout << poz1 << ' ' << poz2;
        else if(cer == 2)
        {
            if(ogc == 'V')
            {
                for(l = 1; l <= nrs; l++)
                {
                    for(i = s*ls; i >= (s-1)*ls + 1; i--)
                    {
                        for(j = ls; j >= 1; j--)
                            fout << m[i][j];
                        fout << '\n';
                    }
                    s++;
                    if(s > nrs)
                        s = 1;
                }
            }
            else if(ogc == 'N')
            {
                for(l = 1; l <= nrs; l++)
                {
                    for(j = ls; j >= 1; j--)
                    {
                        for(i = (s-1)*ls + 1; i <= s*ls; i++)
                            fout << m[i][j];
                        fout << '\n';
                    }
                    s++;
                    if(s > nrs)
                        s = 1;
                }
            }
            else if(ogc == 'E')
            {
                for(l = 1; l <= nrs; l++)
                {
                    for(i = (s-1)*ls + 1; i <= s*ls; i++)
                    {
                        for(j = 1; j <= ls; j++)
                            fout << m[i][j];
                        fout << '\n';
                    }
                    s++;
                    if(s > nrs)
                        s = 1;
                }
            }
            else if(ogc == 'S')
            {
                for(l = 1; l <= nrs; l++)
                {
                    for(j = 1; j <= ls; j++)
                    {
                        for(i = s*ls; i >= (s-1)*ls + 1; i--)
                            fout << m[i][j];
                        fout << '\n';
                    }
                    s++;
                    if(s > nrs)
                        s = 1;
                }
            }
        }
    }
    else
    {
        c = 'E';
        for(i = 1; i <= lt; i++)
        {
            for(j = 1; j <= lt; j++)
                t[i][j] = it;
        }
        cpoz1 = poz1;
            cpoz2 = poz2;
        while(c != '\n')
        {
            if(c == 'N')
            {
                poz1 -= ls;
                cpoz1 = poz1;
                for(j = ls; j >= 1; j--)
                {
                    for(i = (s-1)*ls + 1; i <= s*ls; i++)
                    {
                        if(m[i][j] == 'A')
                            t[poz1][poz2]++;
                        else if(m[i][j] == 'S')
                            t[poz1][poz2]--;
                        poz2++;
                    }
                    poz2 = cpoz2;
                    poz1++;
                }
                s++;
                if(s > nrs)
                    s = 1;
                poz1 = cpoz1;
            }
            if(c == 'S')
            {
                poz1 += ls;
                cpoz1 = poz1;
                for(j = 1; j <= ls; j++)
                {
                    for(i = s*ls; i >= (s-1)*ls + 1; i--)
                    {
                        if(m[i][j] == 'A')
                            t[poz1][poz2]++;
                        else if(m[i][j] == 'S')
                            t[poz1][poz2]--;
                        poz2++;
                    }
                    poz2 = cpoz2;
                    poz1++;
                }
                s++;
                if(s > nrs)
                    s = 1;
                poz1 = cpoz1;
            }
            if(c == 'E')
            {
                if(cpoz1 == 1 && cpoz2 == 1 && !ok)
                {
                    poz1 = 1;
                    poz2 = 1;
                    ok = true;
                }
                else
                {
                    poz2 += ls;
                    cpoz2 = poz2;
                    poz1 = cpoz1;
                }
                for(i = (s-1)*ls + 1; i <= s*ls; i++)
                {
                    for(j = 1; j <= ls; j++)
                    {
                        if(m[i][j] == 'A')
                            t[poz1][poz2]++;
                        else if(m[i][j] == 'S')
                            t[poz1][poz2]--;
                        poz2++;
                    }
                    poz2 = cpoz2;
                    poz1++;
                }
                s++;
                if(s > nrs)
                    s = 1;
                poz1 = cpoz1;
            }
            if(c == 'V')
            {
                poz2 -= ls;
                cpoz2 = poz2;
                for(i = s*ls; i >= (s-1)*ls + 1; i--)
                {
                    for(j = ls; j >= 1; j--)
                    {
                        if(m[i][j] == 'A')
                            t[poz1][poz2]++;
                        else if(m[i][j] == 'S')
                            t[poz1][poz2]--;
                        poz2++;
                    }
                    poz2 = cpoz2;
                    poz1++;
                }
                s++;
                if(s > nrs)
                    s = 1;
                poz1 = cpoz1;
            }
            fin.get(c);
        }
        for(i = 1; i <= lt; i++)
        {
            for(j = 1; j <= lt; j++)
                fout << t[i][j] << ' ';
            fout << '\n';
        }
    }
    return 0;
}
