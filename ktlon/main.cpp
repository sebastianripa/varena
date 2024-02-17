#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("ktlon.in");
ofstream fout ("ktlon.out");

int v[10001];

int main()
{
    int c, n, k, i, j, nrr = 0, nrf = 0, nre = 0, nrem = 0, l, cnrr = 0, cnrf = 0, s1 = 0, s2 = 0;
    fin >> c >> n >> k;
    if(c == 1)
    {
        for(l = 1; l <= k; l++)
        {
            for(i = 1; i <= n*2; i++)
                fin >> v[i];
            sort(v+1, v+n+1);
            sort(v+n+1, v+n*2+1);
            if(v[n] < v[n*2])
                nrr++;
        }
        fout << nrr << '\n';
    }
    else
    {
        for(l = 1; l <= k; l++)
        {
            s1 = 0;
            s2 = 0;
            for(i = 1; i <= n*2; i++)
                fin >> v[i];
            sort(v+1, v+n+1);
            sort(v+n+1, v+n*2+1);
            for(i = n*2; i >= n+1; i--)
            {
                if(v[i] > v[n])
                    cnrr++;
                else
                    break;
            }
            if(cnrr != 0)
            {
                for(i = n, j = n*2; i >= 1, j >= n+1 && cnrr != 0; i--, j--)
                {
                    s1 += v[i];
                    s2 += v[j];
                    cnrr--;
                }
                nrr += s2-s1;
                continue;
            }
            for(i = n; i >= 1; i--)
            {
                if(v[i] > v[n*2])
                    cnrf++;
                else
                    break;
            }
            for(i = n, j = n*2; i >= 1, j >= n+1 && cnrf != 0; i--, j--)
            {
                s1 += v[i];
                s2 += v[j];
                cnrf--;
            }
            nrf += s1-s2;
        }
        fout << max(nrr, nrf);
    }
    return 0;
}
