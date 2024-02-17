#include <bits/stdc++.h>

using namespace std;

ifstream fin ("puteri3.in");
ofstream fout ("puteri3.out");

int main()
{
    int n, b, e, c, s = 0, i;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> b >> e;
        b %= 10;
        if(b == 1)
            s++;
        else if(b == 2)
        {
            if(e%4 == 1)
                s += 2;
            else if(e%4 == 2)
                s += 4;
            else if(e%4 == 3)
                s += 8;
            else if(e > 0)
                s += 6;
        }
        else if(b == 3)
        {
            if(e%4 == 1)
                s += 3;
            else if(e%4 == 2)
                s += 9;
            else if(e%4 == 3)
                s += 7;
            else if(e > 0)
                s++;
        }
        else if(b == 4)
        {
            if(e%2 == 1)
                s += 4;
            else if(e > 0)
                s += 6;
        }
        else if(b == 5)
        {
            if(e > 0)
                s += 5;
        }
        else if(b == 6)
        {
            if(e > 0)
                s += 6;
        }
        else if(b == 7)
        {
            if(e%4 == 1)
                s += 7;
            else if(e%4 == 2)
                s += 9;
            else if(e%4 == 3)
                s += 3;
            else if(e > 0)
                s += 1;
        }
        else if(b == 8)
        {
            if(e%4 == 1)
                s += 8;
            else if(e%4 == 2)
                s += 4;
            else if(e%4 == 3)
                s += 2;
            else if(e > 0)
                s += 6;
        }
        else if(b == 9)
        {
            if(e%2 == 1)
                s += 9;
            else if(e > 0)
                s++;
        }
        if(e == 0 && b != 1)
            s++;
        s %=10;
    }
    fout << s;
    return 0;
}
