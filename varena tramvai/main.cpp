#include <fstream>

using namespace std;

ifstream fin ("tramvai.in");
ofstream fout ("tramvai.out");

int v[100];

int main()
{
    int n, t, x, s = 0, sm = 1000000000, i, j;
    fin >> n >> t;
    for(i = 1; i <= n; i++)
    {
        s = 0;
        fin >> x;
        for(j = 1; j <= x; j++)
            fin >> v[j];
        j = 1;
        while(s < t)
        {
            s += v[j];
            if(j == x)
                j = 1;
            else
                j++;
        }
        if(sm > s)
            sm = s;
    }
    fout << sm - t;
    return 0;
}
