#include <fstream>

using namespace std;

ifstream fin ("tir1.in");
ofstream fout ("tir1.out");

int main()
{
    int h, f, d, g, ph1, ph2, pd1 ,pd2;
    fin >> h >> f >> d >> g;
    if(g == 0 || f == 0 || h == 0 || g == 0)
        fout << "nu";
    else
    {
        ph1 = h/g;
        ph2 = h%g;
        pd1 = d/f;
        pd2 = d%f;
        if(ph2 == 0 && pd2 == 0)
            fout << "da";
        else if(ph2 == 0)
        {
            if(f/pd2 == 0)
                fout << "da";
            else
                fout << "nu";
        }
        else if(pd2 == 0)
        {
            if(g/ph2 == 0)
                fout << "da";
            else
                fout << "nu";
        }
        else
        {
            ph2 = g/ph2;
            pd2 = f/pd2;
            if(ph1 == pd1 && ph2 == pd2)
                fout << "da";
            else
                fout << "nu";
        }

    }
    return 0;
}
