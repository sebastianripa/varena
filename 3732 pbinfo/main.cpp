#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("seism.in");
ofstream fout ("seism.out");

pair <int, int> v[100001];

int main()
{
    int c, n, i, x, a = 1, m = 0, nrs = 0;
    bool ok = false;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(x == 1)
        {
            if(ok == 0)
            {
                ok = 1;
                v[a].first = i;
            }
        }
        else
        {
            if(ok == 1)
            {
                ok = 0;
                v[a].second = i-1;
                a++;
            }
        }
    }
    v[a] = {n+1, n+1};
    if(c == 1)
    {
        a--;
        for(i = 1; i <= a; i++)
        {
            if(v[i].first - v[i-1].second - 1 >= 2)
            {
                if(v[i+1].first - v[i].second - 1 >= 2)
                {
                    if(m < v[i].second - v[i].first + 1)
                        m = v[i].second - v[i].first + 1;
                }
            }
        }
        fout << m;
    }
    else if(c == 2)
    {
        a--;
        for(i = 1; i <= a; i++)
        {
            if(v[i].first - v[i-1].second - 1 >= 2)
            {
                if(v[i+1].second - v[i].first - 1 >= 2)
                    nrs++;
            }
        }
        fout << nrs;
    }
    return 0;
}
