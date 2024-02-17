#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("numere.in");
ofstream fout ("numere.out");

int main()
{
    int n = 0, i = 1, maxi = 0, a, b, s = 0, p;
    fin >> a;
    while(fin >> b)
    {
        if(b - a == i)
        {
            s += i;
            i++;
            a = b;
        }
        else
        {
            if(maxi < i)
            {
                maxi = i;
                p = a - s;
            }
            s = 0;
            i = 1;
        }
        n++;
        a = b;
    }
    fout << p << " ";
    for(i = 1; i <= maxi-1; i++)
    {
        p += i;
        fout << p << " ";
    }
    return 0;
}
