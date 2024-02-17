#include <fstream>


using namespace std;

ifstream fin ("ciffrecv.in");
ofstream fout ("ciffrecv.out");

int vf[8];

int main()
{
    int x, f2 = 0, f3 = 0, f5 = 0, f7 = 0;
    while(fin >> x)
    {
        if(x == 2)
            f2++;
        else if(x == 3)
            f3++;
           else if(x == 5)
            f5++;
            else if(x == 7)
            f7++;
    }
    if(f7 != 0)
        fout << 7 << " " << f7;
    else if(f5 != 0)
        fout << 5 << " " << f5;
    else if(f3 != 0)
        fout << 3 << " " << f3;
	else if(f2 != 0)
        fout << 2 << " " << f2;
    return 0;
}
