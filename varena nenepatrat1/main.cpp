#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nenepatrat.in");
ofstream fout ("nenepatrat.out");

int main()
{
    unsigned long long n, s = 1, s1 = 1, cnt = 0, d = 2;
    fin >> n;
    while(d*d <= n)
    {
        cnt = 0;
        while(n%d == 0)
        {
            n /= d;
            cnt++;
        }
        s *= (cnt + 1);
        s1 *= (cnt*2 + 1);
        d++;
    }
    if(n != 1)
    {
        s *= 2;
        s1 *= 3;
    }
    fout << (s1 - 1)/2 - s + 1;
    return 0;
}
