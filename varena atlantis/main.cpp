#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("atlantis.in");
ofstream fout ("atlantis.out");

int v[100001], v2[100001];

int main()
{
    int n, nrms = 0, k, x, c, i, j;
    fin >> c >> n >> k;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(k > x)
                nrms++;
        }
        fout << nrms;
    }
    else if(c == 2)
    {
         for(i = 1; i <= n; i++)
         {
             fin >> v[i];
             v2[i] = v[i];
         }
         sort(v2 + 1, v2 + n + 1);
         for(i = 1; i <= n; i++)
         {
             for(j = 1; j <= n; j++)
             {
                 if(v2[i] == v[j])
                 {
                     fout << j << " ";
                     break;
                 }
             }
         }
    }
    else
    {
        for(i = 1; i <= n; i++)
         {
             fin >> v[i];
             v2[i] = v[i];
         }
         sort(v2 + 1, v2 + n + 1);
         for(i = 1; i <= n; i++)
         {
             for(j = 1; j <= n; j++)
             {
                 if(v2[j] == v[i])
                 {
                     fout << j << " ";
                     break;
                 }
             }
         }
    }
    return 0;
}
