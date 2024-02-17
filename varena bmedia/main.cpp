#include <fstream>

using namespace std;

ifstream fin ("bmedia.in");
ofstream fout ("bmedia.out");

int countDigit(int n)
{
    int x = 0;
    while(n != 0)
    {
        n /= 10;
        x++;
    }
    return x;
}

long long putere(int n)
{
    long long p = 1;
    for(int i = 1; i <= n; i++)
        p = p*10;
    return p;
}

int main()
{
    int n, i, c;
    long long x = 0;
    fin >> n;
    c = countDigit(n);
    for(i = 1; i <= c - 1 ;i++)
        x += (9*putere(i - 1))*i;
    fout << x + (n - putere(c - 1) + 1)*c;
    return 0;
}
