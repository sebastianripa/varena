#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("mrgary.in");
ofstream fout ("mrgary.out");

int main()
{
    long long T, V, R, i;
    fin >> T;
    for(i = 1; i <= T; i++)
    {
        fin >> V >> R;
        if(V == 0 && R == 0)
            fout << "Yena" << '\n';
        else if(V == 0 || R == 0)
            fout << "Gary" << '\n';
        else if(V == R)
            fout << "Yena" << '\n';
        else if(V != R)
            fout << "Gary" << '\n';
    }
    return 0;
}
