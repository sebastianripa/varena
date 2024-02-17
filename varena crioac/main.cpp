#include <fstream>

using namespace std;

ifstream fin ("crioac.in");
ofstream fout ("crioac.out");

int main()
{
    int n, x, y, k = 1, a = 0, b, ad = 0;
    fin >> n >> x >> y;
    b = n+1;
    while(b > 0 && a < n+1)
    {
        if(a < n+1)
            a += x;
        if(b > 0)
            b -= y;
        if(a == b)
            ad = a;
        if(x > y && a < n+1)
            k++;
        else if(y > x && b > 0 || y == x && b > 0 && a < n+1)
            k++;
    }
    fout << k << '\n' << ad;
    return 0;
}
