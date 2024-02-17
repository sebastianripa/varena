#include <fstream>

using namespace std;

ifstream fin ("carti1.in");
ofstream fout ("carti1.out");

int v[100001];

int main()
{
    int n, nrbp = 0, i, x;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        v[x] = i;
    }
    for(i = 2; i <= n; i++)
    {
        if(v[i] < v[i-1])
            nrbp++;
    }
    fout << nrbp;
    return 0;
}
