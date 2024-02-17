#include <fstream>

using namespace std;

ifstream fin ("norocos.in");
ofstream fout ("norocos.out");

int v[1000001], k;

bool prim(int n)
{
    int i;
    for(i = 3; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool descompunere(int n)
{
    int t = 0, nr = 3, a = 0;
    if(prim(n) == true)
        return false;
    while(n != 1)
    {
        a = 0;
        while(n%nr == 0)
        {
            n /= nr;
            a++;
        }
        if(prim(nr) == true)
            nr += 2;
        else
        {
            while(prim(nr) == false)
                nr += 2;
        }
        if(a != 0)
            t++;
        if(t > k)
            return false;
    }
    if(t == k)
        return true;
    else
        return false;
}

int main()
{
    int c, n, i, mini = 1000000, maxi = 0, x, nrkn = 0;
    fin >> c >> n >> k;
    if(c == 1)
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(x%2 == 1)
            {
                if(maxi < x)
                    maxi = x;
                if(mini > x)
                    mini = x;
            }
        }
        fout << mini << ' ' << maxi;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            if(x%2 == 1)
            {
                if(v[x] == 1)
                    nrkn++;
                else if(descompunere(x) == true)
                {
                    nrkn++;
                    v[x] = 1;
                }
            }
        }
        fout << nrkn << '\n';

    }
    return 0;
}
