#include <fstream>

using namespace std;

ifstream fin ("cardinal.in");
ofstream fout ("cardinal.out");

int main()
{
    int n, x, i, j;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        if(x%4 == 0)
        {
            x /= 8;
            for(j = 1; j <= x; j++)
                fout << "URDLDLUR";
        }
        else
            fout << "IMPOPSIBIL";
        fout << '\n';
    }
    return 0;
}
