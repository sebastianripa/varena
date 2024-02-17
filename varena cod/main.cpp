#include <fstream>

using namespace std;

ifstream fin ("cod.in");
ofstream fout ("cod.out");

int v[100001];

int main()
{
    long long c, n, i, j, x, s = 0, sm = 0;
    char h;
    fin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            fin.get(h);
            for(j = 2; j <= 15; j++)
            {
                if(x%j == 0)
                    break;
            }
            if(j == 16)
                s++;
        }
        fout << s;
    }
    else if(c == 2)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> v[i];
            fin.get(h);
        }
        for(i = 2; i <= 9; i++)
        {
            sm = 0;
            for(j = 1; j <= n; j++)
            {
                if(v[j]%i == 0)
                    sm++;
            }
            s += sm;
        }
        fout << s;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> v[i];
            fin.get(h);
        }
        for(i = 10; i <= 15; i++)
        {
            sm = 0;
            for(j = 1; j <= n; j++)
            {
                if(v[j]%i == 0)
                    sm++;
            }
            s += sm;
        }
        fout << s;
    }
    return 0;
}
