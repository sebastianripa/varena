#include <fstream>

using namespace std;

ifstream fin ("seism.in");
ofstream fout ("seism.out");

int v[100000];

int main()
{
    int c, n, i, lsc = -1, lsm = 0, nrs = 0;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    if (c < 3)
        for(i = 2; i <= n; i++)
        {
            if(v[i] == 0)
            {
                if (v[i-1] == 0)
                {
                    if(lsc > 0)
                    {
                        nrs++;
                        if(lsm < lsc)
                            lsm = lsc;
                    }
                    lsc = 0;
                }
            }
            else
            {
                if (v[i-1] == 0 && lsc > 0)
                    lsc = -1;

                if(lsc != -1)
                    lsc++;

            }
        }
    else
    {
        for(i = 2; i <= n; i++)
        {
            if(v[i] == 0)
            {
                if (v[i-1] == 1)
                {
                    if (v[i+1] == 0)
                    {
                        // max
                        lsc = 0;
                    }
                }
                if (lsc >= 0)
                {
                    lsc++;
                }
                else
                {
                    if (v[i-1] == 0)
                    {
                        lsc = 0;
                    }
                }
            }
            else
            {
                if(lsc != -1)
                    lsc++;

            }
        }

    }
    if(c == 1)
        fout << lsm;
    else if(c == 2)
        fout << nrs;
    return 0;
}
