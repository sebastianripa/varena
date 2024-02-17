#include <fstream>

using namespace std;

ifstream fin ("sir9i.in");
ofstream fout ("sir9i.out");

int v[49011];

int main()
{
    int n, k, s = 0, sm = 0, sc = 0, i;
    fin >> n >> k;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 3; i <= n; i++)
    {
        s = v[i] + v[i-1] + v[i-2];
        if(sm < s)
            sm = s;
    }
    fout << sm << '\n';
    i = 1;
    s = 0;
    while(k > 0)
    {
        sm = 1;
        sc = v[i];
        while(sc)
        {
            sm *= 10;
            sc /= 10;
        }
        sm /= 10;
        while(sm && k)
        {
            if(k != 0)
                s += (v[i]/sm)%10;
            sm /= 10;
            k--;
        }
        i++;
    }
    fout << s;
    return 0;
}
