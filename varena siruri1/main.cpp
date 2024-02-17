#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("siruri1.in");
ofstream fout ("siruri1.out");

int x[100], y[100];

int main()
{
    int n, i, j;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x[i];
        y[i] = x[i];
    }
    sort(x+1, x+n+1);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(y[i] == x[j])
            {
                fout << j << " ";
                break;
            }
        }
    }
    return 0;
}
