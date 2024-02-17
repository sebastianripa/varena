#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("nrdif.in");
ofstream fout ("nrdif.out");

int v[200001];

int main()
{
    int n, difm = 0, i;
    fin >> n;
    for(i = 1; i <= n; i++)
                fin >> v[i];
    sort(v+1, v+n+1);
    for(i = 2; i <= n; i++)
    {
        if(v[i] > v[i-1])
        {
            if(difm < v[i] - v[i-1])
                difm = v[i] - v[i-1];
        }
        else
        {
            if(difm < v[i-1] - v[i])
                difm = v[i-1] - v[i];
        }
    }
    fout << difm;
    return 0;
}
