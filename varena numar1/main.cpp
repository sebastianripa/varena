#include <fstream>

using namespace std;

ifstream fin ("numar1.in");
ofstream fout ("numar1.out");

int v[10];

int main()
{
    int n, c = 0, cn, uc, p = 1;
    fin >> n;
    cn = n;
    while(cn)
    {
        c++;
        cn /= 10;
    }
    uc = n%10;
    cn = n;
    v[uc] = 1;
    while(p < c)
    {
        if(uc%2 == 1)
        {
            while(uc)
            {
                cn /= 10;
                if(cn == 0)
                    cn = n;
                uc--;
            }
            uc = cn%10;
            if(v[c] == 1)
                break;
            else
                v[c] = 1;
        }
        else
        {
            uc = c - uc;
            if(uc < 0)
                while(uc < 0)
                    uc += c;
            while(uc)
            {
                cn /= 10;
                if(cn == 0)
                    cn = n;
                uc--;
            }
            uc = cn%10;
            if(v[c] == 1)
                break;
            else
                v[c] = 1;
        }
        p++;
    }
    fout << uc;
    return 0;
}
