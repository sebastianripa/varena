#include <fstream>

using namespace std;

ifstream fin ("consiliu.in");
ofstream fout ("consiliu.out");

int v[1450];

int main()
{
    int n, h1, m1, m2, h2, i, t1, t2, t, cont = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> h1 >> m1;
        fin >> h2 >> m2;
        t1 = h1*60+m1;
        t2 = h2*60+m2;
        if(t1 < t2)
        {
            for(t = t1; t < t2; t++)
                v[t]++;
        }
        else
        {
            for(t = t1; t <= 23*60+59; t++)
                v[t]++;
            for(t = 0; t < t2; t++)
                v[t]++;
        }
    }
    for(t = 0; t <= 23*60+59; t++)
    {
        if(v[t] == n)
            cont++;
    }
    fout << cont;
    return 0;
}
