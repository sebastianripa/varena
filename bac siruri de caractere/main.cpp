#include <fstream>
#include <string>

using namespace std;

ifstream fin ("a.in");
ofstream fout ("a.out");

int vf[123], vf2[123];

int main()
{
    char c;
    int i;
    bool enter = false;
    while(fin.get(c))
    {
        if(c != ' ' && !enter)
        {
            vf[c]++;
        }
        else if(c == '\n')
            enter = true;
        if(enter && c != ' ')
        {
            vf2[c]++;
        }
        fout << 'c'<<'\n';
    }
    for(i = 97; i <= 122; i++)
    {
        if(vf[i] != vf2[i])
        {
            fout << "NU";
            break;
        }
    }
    if(i == 122)
        fout << "DA";
    fout << '\n' << c;
    return 0;
}
