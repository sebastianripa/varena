#include <fstream>

using namespace std;

ifstream fin ("abc1.in");
ofstream fout ("abc1.out");

int main()
{
    long long a, b, c, uc;
    fin >> a >> b >> c;
    if(b == 0)
        fout << 1;
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
        uc = a%10;
        fout << (uc*uc*uc)%10;
    }
    return 0;
}
