#include <fstream>

using namespace std;

ifstream fin ("subcresc.in");
ofstream fout ("subcresc.out");

int main()
{
    int n, x, ogx, sm = 0, s = 0, i;
    fin >> n >> x;
    for(i = 2; i <= n; i++)
    {
        ogx = x;
        fin >> x;
        if (x > ogx)
            s++;
        else
        {
            s++;
            if(sm < s)
                sm = s+1;
            s = 0;
        }
    }
    fout << sm;
    return 0;
}
