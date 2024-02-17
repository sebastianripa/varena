#include <bits/stdc++.h>

using namespace std;

ifstream fin ("amprenta.in");
ofstream fout ("amprenta.out");

int main()
{
    long long c, n, s1 = 0, i = 1, s2 = 0;
    fin >> c >> n;
    if(c == 1)
    {
        while(n > 9)
        {
            while(n)
            {
                if(i%2 == 1)
                    s1 += n%10;
                else
                    s2 += n%10;
                i++;
                n /= 10;
            }
            n = max(s1, s2) - min(s1, s2);
        }
        if(n == 6)
            fout << 5;
        else if(n == 7)
            fout << 4;
        else if(n == 8)
            fout << 3;
        else if(n == 9)
            fout << 2;
        else
            fout << n;
    }
    return 0;
}
