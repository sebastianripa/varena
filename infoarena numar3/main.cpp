#include <bits/stdc++.h>

using namespace std;

ifstream fin ("numar3.in");
ofstream fout ("numar3.out");

char v[5000005];

int main()
{
    int n, i, mini = 10, j, aux;
    fin >> n;
    fin.get(v[0]);
    for(i = 1; i <= n; i++)
    {
        fin.get(v[i]);
        v[i] -= 48;
        if(mini > v[i])
            mini = v[i];
    }
    for(i = n; i >= 1; i--)
    {
        if(v[i] != mini)
        {
            for(j = i - 1; j >= 1; j--)
            {
                if(v[i] > v[j])
                {
                    aux = v[j];
                    v[j] = v[i];
                    v[i] = aux;
                    break;
                }
            }
            if(j != 0)
                break;
        }
    }
    sort(v+j+1, v+n+1);
    for(i = 1; i <= n; i++)
    {
        aux = v[i];
        fout << aux;
    }
    return 0;
}
