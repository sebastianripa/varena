#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("cosuri.in");
ofstream fout ("cosuri.out");

int v[500001], vf[500001];

int main()
{
    int c, n, i, s = 0, nrm;
    bool ok = true;
    fin >> c >> n;
    for(i = 1; i <= n*2; i++)
    {
        fin >> v[i];
        vf[v[i]]++;
        s += v[i];
    }
    if(c == 1)
    {
        sort(v+1, v+n*2+1);
        fout << v[1]+v[2] << " " << v[n*2-1] + v[n*2];
    }
    else
    {
        if(s%n == 0)
           cout << "NU";
        else
        {
            nrm = s/n;;
            for(i = 1; i <= n*2; i++)
            {
                if(vf[nrm - v[i]] != 0)
                {
                    int term2;
                    vf[nrm - v[i]]--;
                    term2 = nrm-v[i];

                }
            }
        }

    }
    return 0;
}
