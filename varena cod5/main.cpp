#include <fstream>

using namespace std;

ifstream fin ("cod5.in");
ofstream fout ("cod5.out");

int v[100];

int main()
{
    int n, i, x;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        v[x]++;
    }
    for(i = 0; i <= 99; i++)
    {
        if(v[i]%2 == 1)
            fout << i;
    }
    return 0;
}
