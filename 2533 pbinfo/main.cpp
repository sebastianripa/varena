#include <fstream>

using namespace std;

ifstream fin ("secventaincadrata.in");
ofstream fout ("secventaincadrata.out");

int vf1[10], vf2[10], vb[10];

int main()
{
    long long dif, dmax = 0;
    int i = 0, x;
    while(fin >> x)
    {
        i++;
        if(vb[x] == 0)
        {
            vf1[x] = i;
            vb[x] = 1;
        }
        else
            vf2[x] = i;
    }
    for(i = 0; i <= 9; i++)
    {
        dif = vf2[i] - vf1[i] + 1;
        if(dmax < dif)
            dmax = dif;
    }
    fout << dmax << '\n';
    for(i = 0; i <= 9; i++)
    {
        dif = vf2[i] - vf1[i] + 1;
        if(dif == dmax)
            fout << i << ' ';
    }
    return 0;
}
