#include <fstream>

using namespace std;

ifstream fin ("plaja1.in");
ofstream fout ("plaja1.out");

int main()
{
    int n, a, b, i, x, y, r;
    fin >> n >> a;
    x = a;
    for(i = 0; i < n-1; i++)
    {
        fin >> b;
        x = a*b;
        while(b)
        {
            r = a%b;
            a = b;
            b = r;
        }
        y = x/a;
        a = y;
    }
    fout << y;
    return 0;
}
