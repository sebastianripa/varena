#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("abc1.in");
ofstream fout ("abc1.out");

int main()
{
    int a, b, c, uc;
    fin >> a >> b >> c;
    if(b%4 == 0)
    {
        uc = a%10;
        fout << (uc*uc*uc*uc)%10;
    }
    else if(b%4 == 1)
        fout << a%10;
    else if(b%4 == 2)
    {
        uc = a%10;
        fout << (uc*uc)%10;
    }
    else
    {
        if(c%2 == 0)
        {
            fout << a%10;
            return 0;
        }

        uc = a%10;
        fout << (uc*uc*uc)%10;
    }
    return 0;
}
