#include <fstream>

using namespace std;

ifstream fin ("jimjam.in");
ofstream fout ("jimjam.out");

int main()
{
    long long a, b, z, d, dif;
    fin >> a >> b >> z >> d;
    if(z%2 == 0)
        fout << (a-b)*(z/2) << ' ';
    else
        fout << (a-b)*((z-1)/2)+a << ' ';
    dif = a-b;
    if(dif == 0)
    {
        if(d == a)
            fout << 1;
        else
            fout << 0;
    }
    else
    {
        if(d%dif == 0)
            fout << (d/dif)*2;
        else
        {
            d -= b;
            if(d%dif == 0)
                fout << (d/dif)*2 + 1;
            else
                fout << 0;
        }
    }
    return 0;
}
