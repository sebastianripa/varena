#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ssm.in");
ofstream fout ("ssm.out");

int v[6000005];

int main()
{
    int n, i, in, sf, pin = 2, mb = 0, s = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    mb = v[1];
    in = 1;
    sf = 1;
    for(i = 2; i <= n; i++)
    {
        s += v[i];
        if(s > mb)
        {
            mb = s;
            in = pin;
            sf = i;
        }
        if(s < 0)
        {
            s = 0;
            pin = i+1;
        }
    }
    fout << mb << ' ' << in << ' ' << sf;
    return 0;
}
