#include <fstream>

using namespace std;

ifstream fin ("stergeri.in");
ofstream fout ("stergeri.out");

long long v[100001], v3[100001];

int main()
{
    long long n, scm = 0, v1, v2, i, sc = 0, ce, nrm = 0, nes = 0, nesm = 0, i2;
    bool sv = false;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    while(!sv)
    {
        v1 = 0;
        v2 = 0;
        scm = 0;
        sc = 0;
        nes = 0;
        for(i = 1; i <= n; i++)
        {
            sc = 0;
            ce = v[i];
            while(ce)
            {
                sc += ce%10;
                ce /= 10;
            }
            v3[i] = sc;
            if(scm < sc)
                scm = sc;
        }
        for(i = 1; i <= n; i++)
        {
            if(v3[i] == scm)
            {
                if(v1 == 0)
                    v1 = i;
                else
                    v2 = i;
            }
        }
        if(v2 == 0)
        {
            v[v1] = 0;
            nes++;
        }
        else
        {
            for(i = v1; i <= v2; i++)
            {
                if(v[i] != 0)
                    nes++;
                v[i] = 0;
            }
        }
        if(nesm < nes)
            nesm = nes;
        for(i = 1; i <= n; i++)
        {
            if(v[i] != 0)
                break;
        }
        if(i == n+1)
            sv = true;
        nrm++;
    }
    fout << nrm << " " << nesm;
    return 0;
}
