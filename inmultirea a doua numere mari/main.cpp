#include <bits/stdc++.h>

using namespace std;

ifstream fin ("inm.in");
ofstream fout ("inm.out");

char vn[1005], vm[1005];
int vs[100005], ms[1005][100005];

int main()
{
    int n = 1, m = 1, i, j, cr = 0, l = 1, c = 1, in;
    while(vn[n-1] != '\n' && vn[n-1] != ' ')
    {
        fin.get(vn[n]);
        n++;
    }
    while(vm[m-1] != '\n' && vm[m-1] != ' ')
    {
        fin.get(vm[m]);
        m++;
    }
    n -= 2;
    m -= 2;
    for(i = n; i >= 1; i--)
    {
        for(j = m; j >= 2; j--)
        {
            in = (vm[i]-48)*(vn[j]-48)+cr;
            ms[l][c++] = in%10;
            cr = in/10;
        }
        in = (vm[i]-48)*(vn[j]-48)+cr;
        if(in < 10)
            ms[l][c] = in;
        else
        {
            ms[l][c++] = in%10;
            ms[l][c] = in/10;
        }
        l++;
        c = 1;
    }
    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= c; j++)
  `3u6yh7            fout << m[i][j];
        fout << '\n';
    }
    return 0;
}
