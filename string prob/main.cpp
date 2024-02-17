#include <bits/stdc++.h>

using namespace std;

int j = 1, cs = 1, v[1000005];
char m[8][200];
string s, nrbs;

void inv()
{
    int i;
    char aux;
    for(i = 1; i <= 3; i++)
    {
        aux = m[j][i];
        m[j][i] = m[j][7-i];
        m[j][7-i] = aux;
    }
}

void itob(int n)
{
    int i = 1;
    while(n > 0)
    {
        if(n%2 == 0)
        {
            m[j][i] = '0';
            i++;
        }
        else
        {
            m[j][i] = '1';
            i++;
        }
        n /= 2;
    }
    if(i < 7)
    {
        for(; i <= 7; i++)
            m[j][i] = '0';
    }
    inv();
    for(i = 1; i <= 7; i++, cs++)
        s[cs] = m[j][i];
    j++;
}

void binary(int n)
{
    int i = 1, aux, j;
    while(n > 0)
    {
        if(n%2 == 0)
        {
            nrbs[i] = '0';
            i++;
        }
        else
        {
            nrbs[i] = '1';
            i++;
        }
        n /= 2;
    }
    for(j = 1; j <= i-1; j++)
    {
        aux = nrbs[j];
        nrbs[j] = nrbs[i-j-1];
        nrbs[i-j-1] = aux;
    }
}

void eraseBinary()
{
    int i = 0, j = 0;
    while(i != string::npos)
    {
        binary(j++);
        i = s.find(0, to_string(nrbs));
        if(i != string::npos)
            s.erase(i, to_string(nrbs).length);
        else
            break;
    }
}

int main()
{
    int i, x;
    cin >> s;
    for(i = 0; i < s.length(); i++)
    {
        x = s[i];
        itob(x);
    }
    eraseBinary();
    return 0;
}
