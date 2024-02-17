#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bete.in");
ofstream fout ("bete.out");

int main()
{
    int n, x, min1 = 10001, min2 = 10001, max1 = 0, max2 = 0, k1 = 0, k2 = 0, i;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        min1 = min(x, min1);
        if(max1 < x)
        {
            max1 = x;
            k1 = 0;
        }
        if(max1 == x)
            k1++;
    }
    for(i = 1; i <= n; i++)
    {
        fin >> x;
        min2 = min(x, min2);
        if(max2 < x)
        {
            max2 = x;
            k2 = 0;
        }
        if(max2 == x)
            k2++;
    }
    fout << min1 + max2 << '\n' << max1 + max2 << '\n' << min(k1, k2);
    return 0;
}
