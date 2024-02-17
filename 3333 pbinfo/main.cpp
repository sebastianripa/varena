#include <fstream>

using namespace std;

ifstream fin ("bookface.in");
ofstream fout ("bookface.out");

int SumaDivizori(int n)
{
    int i, sd = 0;
    for(i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            sd += i;
            if(n/i != i)
                sd += n/i;
        }
    }
    return sd;
}

int main()
{
    int n, a, sd, i;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> a;
        a *= a;
        sd = SumaDivizori(a);
        fout << sd << '\n';
    }
    return 0;
}
