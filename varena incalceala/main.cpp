#include <bits/stdc++.h>

using namespace std;

ifstream fin ("incalceala.in");
ofstream fout ("incalceala.out");

char v[20002];

int main()
{
    int n = 0, i, nrpd = 0, nrpi = 0, j;
    char c;
    for(j = 1; j <= 5; j++)
    {
        nrpd = 0;
        nrpi = 0;
        while(v[i] != '\n')
        {
            fin.get(v[i]);
            if(v[i] == '(')
            {
                nrpd++;
                c = '(';
            }
            else if(v[i] == ')')
            {
                nrpi++;
                c = ')';
            }
        }
        if(c != '(')
        {
            if(nrpd == nrpi)
                fout << 1 << '\n';
            else
                fout << 0 << '\n';
        }
        else
            fout << 0 << '\n';
        i++;
    }
    return 0;
}
