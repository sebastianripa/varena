#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("palindrom2.in");
ofstream fout ("palindrom2.out");

long long inv(long long n)
{
    long long in = 0;
    while(n != 0)
    {
        in = in*10 + n%10;
        n /= 10;
    }
    return in;
}

long long c3(long long n)
{
    long long t, j2 = 0, j1;
    int l = log10(n) + 1;

    if(l < log10(n + 1) + 1) // if all 9's
    {
        n += 2;
        return n;
    }

    if (l == 1) // if single digit
        return n+1;

    j1 = n / pow(10, l/2);

    if(l%2 == 0)
        j2 = inv(j1);
    else
        j2 = inv(j1/10);

    t = j1*pow(10, l/2) + j2;

    if(t <= n)
    {
        j1++;

        if(l%2 == 0)
            j2 = inv(j1);
        else
            j2 = inv(j1/10);

        t = j1*pow(10, l/2) + j2;

    }
    return t;
}

bool ePalindrom(long long n)
{
    if(inv(n) == n)
        return true;
    return false;
}

bool eAproapePalindrom(long long n)
{
    long long in = inv(n), verif = 0;

    if (n == in)
        return false;

    while(n > 0 || in > 0)
    {
        if(n%10 != in%10)
        {
            verif++;
            if(verif > 2)
                return false;
        }

        n /= 10;
        in /= 10;
    }
    return true;
}

int main()
{
    long long c, n, i, x, nrp = 0;
    fin >> c >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(c == 1)
        {
            if(ePalindrom(x))
                nrp++;
        }
        else if(c == 2)
        {
            if(eAproapePalindrom(x))
                nrp++;
        }
        else
            fout << c3(x) << " ";
    }
    if (c != 3)
        fout << nrp;
    return 0;
}
