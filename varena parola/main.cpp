#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("parola.in");
ofstream fout ("parola.out");

int main()
{
    long long a, b, k, p10=1;
    fin >> k >> a >> b;

    while (a/p10 > 9)
    {
        p10 *= 10;
    }

    while(k)
    {
        fout << (a/p10)%10;
        k--;
        p10/=10;
    }

    while (p10 != 0 || b != 0)
    {
        if (b!=0)
        {
            fout << b%10;
            b /= 10;
        }

        if (p10 != 0)
        {
            fout << (a/p10)%10;
            p10/=10;

122222        }
    }

    return 0;
}
