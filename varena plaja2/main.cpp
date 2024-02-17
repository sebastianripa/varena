#include <fstream>

using namespace std;

ifstream fin ("plaja2.in");
ofstream fout ("plaja2.out");

int main()
{
    int n, a, b, i, r;
    fin >> n >> a;
    for(i = 0; i < n-1; i++)
    {
        b = a;
        fin >> a;
        while(b)
        {
            r = a%b;
            a = b;
            b = r;
        }
    }
    fout << a;
    return 0;
}
