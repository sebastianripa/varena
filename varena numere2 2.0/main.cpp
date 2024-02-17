#include <fstream>

using namespace std;

ifstream fin ("numere2.in");
ofstream fout ("numere2.out");

int main()
{
    int n, x, c = 0, suma, i, j;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        suma = x;
        c = 0;
        while(suma < x*x)
        {
            c++;
            if(suma < x*x)
                suma = suma+(x+c)+(x-c);
        }
        if(suma == x*x)
        {
            for(j = x-c; j <= x+c; j++)
                fout << j << " ";
        }
        fout << '\n';

    }
    return 0;
}
