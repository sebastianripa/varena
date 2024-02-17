#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("concurs.in");
ofstream fout ("concurs.out");

long long v[100001];

int main()
{
    long long c, n, i, p = 0, pm = 0, e, nrpm = 0, p1 = 0, p2 = 0, p3 = 0;
    char pr, ogpr = '0';
    bool citit = false;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            p = 0;
            citit = false;
            fin >> e;
            fin.get(pr);
            while(fin.get(pr))
            {
                if(pr == '\n')
                    break;
                if(ogpr == '0' && citit == false)
                {
                    citit = true;
                    ogpr = pr;
                    p += (pr - 48);
                    continue;
                }
                if(pr == '0' && ogpr == '1')
                    p += 9;
                else
                    p += (pr - 48);
                ogpr = pr;
            }
            if(pm < p)
                pm = p;
            v[i] = p;
        }
        for(i = 1; i <= n; i++)
        {
            if(v[i] == pm)
                nrpm++;
        }
        fout << pm << " " << nrpm;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            p = 0;
            citit = false;
            ogpr = '0';
            fin >> e;
            fin.get(pr);
            while(fin.get(pr))
            {
                if(pr == '\n')
                    break;
                if(ogpr == '0' && citit == false)
                {
                    citit = true;
                    ogpr = pr;
                    p += (pr - 48);
                    continue;
                }
                if(pr == '0' && ogpr == '1')
                    p += 9;
                else
                    p += (pr - 48);
                ogpr = pr;
            }
            if(e == 1)
                p1 += p;
            else if(e == 2)
                p2 += p;
            else
                p3 += p;
        }
        if(p1 == 0 && p2 == 0 && p3 == 0)
            fout << "FARA CAMPION";
        else if(p1 > p2 && p1 > p3)
            fout << 1 << " " << p1;
        else if(p2 > p1 && p2 > p3)
            fout << 2 << " " << p2;
        else if(p3 > p1 && p3 > p2)
            fout << 3 << " " << p3;
        else if(p1 == p2 && p2 > p3)
            fout << 1 << " " << 2 << " " << p1;
        else if(p2 == p3 && p3 > p1)
            fout << 2 << " " << 3 << " " << p2;
        else if(p1 == p3 && p1 > p2)
            fout << 1 << " " << 3 << " " << p3;
        else if(p1 == p2 && p2 == p3)
            fout << 1 << " " << 2 << " " << 3 << " " << p3;
    }
    return 0;
}
