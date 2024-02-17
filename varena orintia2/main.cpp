#include <fstream>

using namespace std;

ifstream fin ("orintia.in");
ofstream fout ("orintia.out");

int v[10];

int main()
{
    long long n, x, i;
    fin >> n;
    bool afisat  = false, afisat2 = false;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        x += (n-i);
        v[x%10] = 1;
    }
    for(i = 0; i <= 9; i++)
    {

        if(v[0] == 1 && afisat == false)
        {
            if(i != 0 && v[i] == 1)
            {
                fout << i;
                v[i] = 2;
                fout << 0;
                afisat = true;
                afisat2 = true;
            }
        }
        if(v[i] == 1 && i != 0)
        {
            fout << i;
            afisat2 = true;
        }
    }
    if(afisat2 == false)
        fout << 0;
    return 0;
}
