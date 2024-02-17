#include <fstream>

using namespace std;

ifstream fin ("pinochio.in");
ofstream fout ("pinochio.out");

int main()
{
    int n, p, k, i = 1;
    fin >> n >> p >> k;

    while(i <= k)
    {
        if(i%7 == 0 || i%7 == 6)
            n--;
        else
            n += p;
        i++;
    }
    fout << n;
    return 0;
}
