#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dezechilibru.in");
ofstream fout ("dezechilibru.out");

int main()
{
    int t, n, cm, s = 0, nrc = 0, cn, i, mij, dez, m = 0, nm, pn;
    fin >> t;
    for(i = 1; i <= t; i++)
    {
        s = 0;
        nrc = 0;
        fin >> n;
        if(n != 0)
        {
            if(i == 1)
                pn = n;
            cn = n;
            while(cn)
            {
                s += (cn%10);
                nrc++;
                cn /= 10;
            }
            cn = n;
            mij = nrc/2+1;
            while(nrc != mij)
            {
                cn /= 10;
                nrc--;
            }
            cm = cn%10;
            s -= cm;
            cm *= cm;
            dez = max(s, cm) - min(s, cm);
            if(dez > m)
            {
                nm = n;
                m = dez;
            }
        }
    }
    if(m == 0)
        nm = pn;
    fout << nm;
    return 0;
}
