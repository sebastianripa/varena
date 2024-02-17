#include <fstream>

using namespace std;

ifstream fin ("bitona.in");
ofstream fout ("bitona.out");

int main()
{
    int n, ox, x, sec = 0, i;
    bool cresc = false, descresc = false, c = false, d = false, c2 = false, d2 = false;
    fin >> n >> x;
    for(i = 2; i <= n; i++)
    {
        ox = x;
        fin >> x;
        if(ox < x)
        {
            if(descresc == true)
            {
                sec++;
                descresc = false;
            }
            cresc = true;
        }
        else
        {
            if(cresc == true)
            {
                sec++;
                cresc = false;
            }
            descresc = true;
        }
    }
    if(sec < 4)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}
