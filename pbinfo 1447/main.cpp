#include <fstream>

using namespace std;

ifstream in("forus.in");
ofstream out("forus.out");

int v[31];

int nrc(int a)
{
    int nr = 0;
    while (a > 0)
    {
        ++nr;
        a /= 10;
    }
    return nr;
}

int div(int a)
{
    int nr = 2, x = 2, y;
    while (x * x < a)
    {
        if (a % x == 0)
            ++nr;
        y = a / x;
        if (a % y == 0)
            ++nr;
        ++x;
    }
    if (x * x == a)
        ++nr;
    return nr;
}

int main()
{
    int n, i, j, a, c;
    bool ok;
    in >> c >> n;
    if (c == 1)
    {
        int nr = 0;
        for (i = 1; i <= n; ++i)
        {
            in >> a;
            ok = 1;
            while (a > 0 && ok == 1)
            {
                if (a % 10 == 0)
                    ok = 0;
                a /= 10;
            }
            if (ok == 1)
                ++nr;
        }
        out << nr;
    }
    else
    {
        int p, nr1, nr2, ba, MIN, nrmin;
        bool ok;
        for (i = 1; i <= n; ++i)
        {
            in >> a;
            MIN = div(a);
            nrmin = a;
            p = 1;
            nr2 = 0;
            while (p <= a / 10)
            {
                ba = a;
                ok = 0;
                if (a / p % 10 != 0)
                {
                    while (ba > 0)
                    {
                        if (ok == 0)
                        {
                            nr1 = ba % (p * 10);
                            ba /= p * 10;
                            ok = 1;
                        }
                        else
                        {
                            nr2 = ba;
                            ba = 0;
                        }
                    }
                    for (int j = 1; j <= nrc(nr2); ++j)
                        nr1 *= 10;
                    nr1 += nr2;
                    if (div(nr1) < MIN)
                    {
                        MIN = div(nr1);
                        nrmin = nr1;
                    }
                    else if (div(nr1) == MIN)
                    {
                        if (nr1 < nrmin)
                            nrmin = nr1;
                    }
                }
                p *= 10;
            }
            out << nrmin << " ";
        }
    }
    return 0;
}
