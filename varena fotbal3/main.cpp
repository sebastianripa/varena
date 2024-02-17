#include <bits/stdc++.h>

using namespace std;

ifstream fin ("fotbal3.in");
ofstream fout ("fotbal3.out");

int vf[10001], vm[10001], va[10001], vp[10001];

int main()
{
    int c, f, m, a, v, i, j, n, nf = 0, nm = 0, na = 0, np = 0, maxi = 0;
    char r, p;
    fin >> c >> r >> f >> m >> a >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> p >> v;
            if(p == 'P')
                np++;
            else if(p == 'F')
                nf++;
            else if(p == 'M')
                nm++;
            else
                na++;
        }
        fout << np << '\n' << nf << '\n' << nm << '\n' << na << '\n';
    }
    else if(c == 2)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> p >> v;
            if(p == r)
            {
                if(maxi < v)
                    maxi = v;
            }
        }
        fout << r << ' ' << maxi << '\n';
    }
    else
    {
        vf[1] = -1;
        vm[1] = -1;
        va[1] = -1;
        vp[1] = -1;
        for(i = 1; i <= n; i++)
        {
            fin >> p >> v;
            if(p == 'P')
            {
                np++;
                vp[np] = v;
            }
            else if(p == 'F')
            {
                nf++;
                vf[nf] = v;
            }
            else if(p == 'M')
            {
                nm++;
                vm[nm] = v;
            }
            else
            {
                na++;
                va[na] = v;
            }
        }
        sort(vp+1, vp+np+1);
        sort(vf+1, vf+nf+1);
        sort(vm+1, vm+nm+1);
        sort(va+1, va+na+1);
        if(vp[1] == -1)
            fout << "nu se poate forma echipa" << '\n';
        else if(vf[1] == -1)
            fout << "nu se poate forma echipa" << '\n';
        else if(vm[1] == -1)
            fout << "nu se poate forma echipa" << '\n';
        else if(va[1] == -1)
            fout << "nu se poate forma echipa" << '\n';
        else
        {
            fout << 'P' << ' ' << vp[np] << '\n';
            for(i = nf; i > nf-f; i--)
                fout << 'F' << ' ' << vf[i] << '\n';
            for(i = nm; i > nm-m; i--)
                fout << 'M' << ' ' << vm[i] << '\n';
            for(i = na; i > na-a; i--)
                fout << 'A' << ' ' << va[i] << '\n';
        }
    }
    return 0;
