#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ruleta.in");
ofstream fout ("ruleta.out");

int v[30001];

int main()
{
    int n, i, nr, j = 1, cont, k;
    bool egalTot = true;
    fin >> n;
    cont  = n - 1;
    fin >> v[1];
    for(i = 2; i <= n; i++)
    {
        fin >> v[i];
        if(v[i-1] != v[i])
            egalTot = false;
    }
    if(egalTot)
        cout << 1;
    else
    {
        for(i = 2; i <= n/2; i++)
        {
            if(cont%i == 0)
            {
                k = i+1;
                j = 1;
                while(v[j] == v[k] && j < i)
                {
                    k++;
                    j++;
                }
                if(j == i)
                {
                    fout << i;
                    break;
                }
            }
        }
    }

    return 0;
}
