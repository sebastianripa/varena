#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("lascoala.in");
ofstream fout ("lascoala.out");

int main()
{
    int n, i, p;
    fin >> n;
    for(i = n-1; i >= 0; i--)
    {
        if(sqrt(i) == (int)sqrt(i))
        {
            p = sqrt(i);
            break;
        }
    }
    fout << n - p*p << '\n';
    for(i = p*p; i > 0; i--)
    {
        if(i%p == 0 && i != p*p)
            fout << '\n';
        fout << i << " ";
    }
    return 0;
}
