#include <bits/stdc++.h>

using namespace std;

ifstream fin ("inginer.in");
ofstream fout ("inginer.out");

queue< pair<int, int> >q;

long long n, l, i, j, i2, i3, j2, j3;
long long m[80][80];
long long vi[4] = {0, 0, 1, -1};
long long vj[4] = {1, -1, 0, 0};

bool functie(int i, int j)
{
    if(i < 0 || j < 0 || i > n+1 || j > l+1)
        return false;
    if(m[i][j] == -1)
        return false;
    return true;
}

int lee(int ii, int ij, int si, int sj)
{
    int i, j, i1, j1, outtie = 0;
    m[ii][ij] = 1;
    q.push(make_pair(ii, ij));
    while(!q.empty() && outtie == 0)
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++)
        {
            i1 = i + vi[d];
            j1 = j + vj[d];
            if(i1 == si && j1 == sj)
            {
                outtie = m[i][j] + 1;
                break;
            }
            if(functie(i1, j1) && m[i1][j1] == 0)
            {
                m[i1][j1] = m[i][j] + 1;
                q.push(make_pair(i1, j1));
            }
        }
    }
    m[ii][ij] = -1;
    for(int ui = 0; ui <= n+1; ui++)
    {
        for(int jj = 0; jj <= l+1; jj++)
        {
            if(m[ui][jj] != -1)
                m[ui][jj] = 0;
        }
    }
    if(outtie > 0)
        outtie--;
    return outtie;
}

int main()
{
    char ch[1000];
    fin >> n >> l;
    fin.get();
    for(int i = 1; i <= n; i++)
    {
        fin >> ch;
        for(int j = 0; j < l; j++)
        {
            if(ch[j] == 'X')
                m[i][j+1] = -1;
        }
    }
    fin >> i2 >> j2 >> i3 >> j3;
    while(i2 != 0)
    {
        fout << lee(i2, j2, i3, j3) << '\n';
        fin >> i2 >> j2 >> i3 >> j3;
    }
    return 0;
}
