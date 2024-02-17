#include <fstream>

using namespace std;

ifstream fin ("cifre.in");
ofstream fout ("cifre.out");

long long prob(long long n)
{
    int c, ogc, c3;
    c = n%10;
    n /= 10;
    ogc = c;
    c = n%10;
    n /= 10;
    while(n != 0)
    {
        c3 = ogc;
        ogc = c;
        c = n%10;
        if(ogc == c || c3 != c)
            return 0;
        n /= 10;
    }
    return 1;
}

int main()
{
    long long a, b, c;
    fin >> a >> b >> c;
    fout << prob(a) << " " << prob(b) << " " << prob(c);
    return 0;
}
