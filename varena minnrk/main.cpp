#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("minnrk.in");
ofstream fout("minnrk.out");

int main()
{
    int k, i;
    char c;
    int vf[10] = {0};

    fin.get(c);
    while(c != ' ');
    {
        vf[c - '0']++;
        fin.get(c);
    }

    fin >> k;

    for(i = 1; i < 10; i++)
    {
        while(vf[i] > 0 && k > 0)
        {
            fout << i;
            k--;
            while(vf[0] > 0 && k > 0)
            {
                fout << 0;
                k--;
                vf[0]--;
            }
            vf[i]--;
        }
    }
    return 0;
}
