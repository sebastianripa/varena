#include <bits/stdc++.h>

using namespace std;

ifstream fin ("disjoint.in");
ofstream fout ("disjoint.out");

int v[100005];

void makeTree (int i, int j)
{
    int aux = i, aux2 = j;
    while(v[aux] != aux)
        aux = v[aux];
    while(v[aux2] != aux2)
        aux2 = v[aux2];
    v[aux2] = aux;
}

bool check (int i, int j)
{
    int aux1 = j, aux2 = i;
    while(v[aux1] != aux1)
        aux1 = v[aux1];
    while(v[aux2] != aux2)
        aux2 = v[aux2];
    if(aux1 == aux2)
        return true;
    else
        return false;
}

int main()
{
    int n, m, cod, x, y, i;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        v[i] = i;
    while(m)
    {
        fin >> cod >> x >> y;
        if(cod == 1)
            makeTree(x, y);
        else
        {
            if(check(x, y))
                fout << "DA" << '\n';
            else
                fout << "NU" << '\n';
        }
        m--;
    }
    return 0;
}
