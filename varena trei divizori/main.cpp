#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

ifstream fin ("treidiv.in");
ofstream fout ("treidiv.out");

int np[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31};

bool ePrim(int x)
{
    for(int i = 0; i < 12; i++)
    {
        if (x == np[i])
            return true;

        if(x%np[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, x, i, s, nr3d = 0;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        s = sqrt(x);
        if(x > 3 && s*s == x)
        {
            if(ePrim(s))
                nr3d++;
        }
    }
    fout << nr3d;
    return 0;
}
