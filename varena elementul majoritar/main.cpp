#include <fstream>

using namespace std;

ifstream fin ("majoritar.in");
ofstream fout ("majoritar.out");

long long vn[3000001];
int vf[3000001];

int main()
{
    int n, x, i, j, k = 1;
    fin >> n;
    bool found;

    for(i = 1; i <= n; i++)
    {
        fin >> x;
        found = false;
        for(j = 1; j < k; j++)
        {
            if (vn[j] == x)
            {
                vf[j]++;
                found = true;
                break;
            }
        }
        if(!found)
        {
            vf[k]++;
            vn[k++] = x;
        }//??
    }
    found = false;
    for(i = 1; i <= n; i++)
    {
        if(vf[i] >= n/2+1)
        {
            fout << vn[i] << " " << vf[i];
            found = true;
            break;
        }
    }
    if(!found)
        fout << -1;
    return 0;
}
