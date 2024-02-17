#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("chibrituri.in");
ofstream fout ("chibrituri.out");

int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
int vv[10] = {4, 2, 2, 2, 3, 2, 3, 2, 4, 3};
int vo[10] = {2, 0, 3, 3, 1, 3, 3, 1, 3, 3};

void next()
{
    if(m2 != 9)
    {
        m2++;
        return;
    }
    m2 = 0;
    if(m1 != 5)
    {
        m1++;
        return;
    }
    m1 = 0;
    if(h1 != 2)
    {
        if(h2 != 9)
        {
            h2++;
            return;
        }
        h2 = 0;
        h1++;
        return;
    }
    if(h2 != 3)
    {
        h2++;
        return;
    }
    h2 = 0;
    h1 = 0;
}

int main()
{
    int nv, no, nrv, nro, nrvar = 0, minimh1, minimh2, minimm1, minimm2, maximh1, maximh2, maximm1, maximm2;
    bool minim = false;
    fin >> nv >> no;
    do
    {
        nrv = vv[h1] + vv[h2] + vv[m1] + vv[m2];
        nro = vo[h1] + vo[h2] + vo[m1] + vo[m2];
        if(nv == nrv && no == nro)
        {
            nrvar++;
            if(minim == false)
            {
                minimh1 = h1;
                minimh2 = h2;
                minimm1 = m1;
                minimm2 = m2;
                minim = true;
            }
            maximh1 = h1;
            maximh2 = h2;
            maximm1 = m1;
            maximm2 = m2;
        }
        next();
    }
    while(h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0);
    fout << nrvar << '\n';
    fout << minimh1 << minimh2 << ':' << minimm1 << minimm2 << '\n';
    fout << maximh1 << maximh2 << ':' << maximm1 << maximm2 << '\n';
    return 0;
}
