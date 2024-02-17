#include <bits/stdc++.h>

using namespace std;

ifstream fin ("topaila.in");
ofstream fout ("topaila.out");

int main()
{
    long long t, k, f, s, i, ans;
    fin >> t;
    while(t--)
    {
        fin >> k >> f >> s;
        ans = k*(k+1)/2;
        if(ans < max(f, s) - min(f, s))
            fout << 0 << '\n';
        else
        {
            ans = ans - f + s;
            if(ans%2 == 0)
                fout << 1 << '\n';
            else
                fout << 0 << '\n';
        }
    }
    return 0;
}
