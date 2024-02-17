#include <bits/stdc++.h>

using namespace std;

ifstream fin ("readunare.in");
ofstream fout ("readunare.out");

void afis(int n)
{
    fout<<"{";
    for(int j=n-1;j>1;j--)
    {
        afis(j);
        fout<<",";
    }
    if(n>0)
        afis(0);
    fout<<"}";
}

int main()
{
    int nr1 = 0, nr2 = 0, s, pd = 0, pi = 0;
    char c;
    fin.get();
    fin.get(c);
    while(c != '\n')
    {
        if(c == '{')
            pd++;
        if(c == '}')
            pi++;
        if(pd == pi && c != ',' && c != ' ')
            nr1++;
        fin.get(c);
    }
    pi--;
    fin.get();
    fin.get(c);
    while(c != '\n')
    {
        if(c == '{')
            pd++;
        if(c == '}')
            pi++;
        if(pd == pi && c != ',' && c != ' ')
            nr2++;
        fin.get(c);
    }
    s = nr1 + nr2;
    if(s > 0)
        afis(s+1);
    else
        afis(0);
    return 0;
}
