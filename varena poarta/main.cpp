#include <bits/stdc++.h>

using namespace std;

ifstream fin ("poarta.in");
ofstream fout ("poarta.out");

struct pozitii
{
    int l1, c1, l2, c2;
};

pozitii v[5005];
int m[255][255], rez[5005];

int main()
{
    int r = 0, i, j, n, ad = 1, cn, ok = 1, OK;
    bool schimbare = false;
    fin >> n;
    cn = n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i].l1 >> v[i].c1 >> v[i].l2 >> v[i].c2;
        m[v[i].l1][v[i].c1] = 1;
        if(v[i].l1 == v[i].l2 && v[i].c1 == v[i].c2)
            m[v[i].l1][v[i].c1] == 0;
    }
    for(i = 1; i <= n; i++)
    {
        if(m[v[i].l2][v[i].c2] == 0)
        {
            r++;
            m[v[i].l1][v[i].c1] = 1;
            rez[i] = 1;
        }
    }
    while(ok != 0)
    {
        schimbare = false;
        for(i = 1; i <= n; i++)
        {
            if(rez[i] == 1)
                continue;
            if(m[v[i].l2][v[i].c2] = 1)
                continue;
            r++;
            m[v[i].l1][v[i].c1] = 0;
            rez[i] = 1;
            schimbare = true;
        }
        if(!schimbare)
        {
            for(i = 1; i <= n; i++)
            {
                if(rez[i] == 1)
                    continue;
                r++;
                m[v[i].l1][v[i].c1] = 0;
                rez[i] = 1;
                break;
            }
        }
        OK = 1;
        for(i = 1; i <= n; i++)
        {
            if(rez[i] == 0)
            {
                OK = 0;
                break;
            }
        }
        if(OK == 0)
            ok = 0;
    }
    fout << r;
    return 0;
}
