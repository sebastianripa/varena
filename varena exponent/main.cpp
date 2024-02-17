#include <fstream>

using namespace std;

ifstream fin ("exponent.in");
ofstream fout ("exponent.out");

int main()
{
    int n, k, x = 0, i, j;
    fin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        j = i;
        while(j%k == 0)
        {
            j /= k;
            x++;
        }
    }
    fout << x;
    return 0;
}
