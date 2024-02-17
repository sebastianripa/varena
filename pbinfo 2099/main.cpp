#include <bits/stdc++.h>

using namespace std;

ifstream fin ("unupatru.in");
ofstream fout ("unupatru.out");

int main()
{
    long long n, x, nr = 0, i, ans = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        ans = 0;
        fin >> x;
        while(x != 4 && x != 1)
        {
            while(x)
            {
                nr += (x%10)*(x%10);
                x /= 10;
            }
            x = nr;
            ans++;
            nr = 0;
        }
        fout << ans << ' ';
    }
    return 0;
}
