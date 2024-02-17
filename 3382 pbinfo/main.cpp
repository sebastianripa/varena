#include <fstream>

using namespace std;

ifstream fin ("robot.in");
ofstream fout ("robot.out");

int v[1000001];

int main()
{
    int c, n, d = 0, nrad = 0, i, L, l, mini = 100101, p = 1, cmax = 0;
    fin >> c;
    if(c == 1)
    {
        fin >> n;
        for(i = 1; i <= n; i++)
        {
            fin >> l >> L;
            d = min(l, L)*p + max(l, L);
            if(v[d] == 0)
            {
                nrad++;
                v[d] = 1;
            }
        }
        fout << nrad;
    }
    else
    {
        fin >> n;
        for(i = 1; i <= n; i++)
        {
            fin >> l >> L;
            cmax = max(l, L);
            while(cmax)
            {
                p *= 10;
                cmax /= 10;
            }
            d = min(l, L)*10 + max(l, L);
            v[d]++;
        }
        for(i = 1; i <= 100100; i++)
        {
            if(mini > v[i] && v[i] != 0)
                mini = v[i];
        }
        fout << mini;
    }
    return 0;
}
