#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bac.txt");

int vf[1000005];

int main()
{
    int x, i, scv = 0, mscv = 0;
    while(fin >> x)
        vf[x]++;
    for(i = 1; i <= x; i++)
    {
        if(i == vf[i] || vf[i] == 0)
            scv += vf[i];
        else
        {
            mscv = max(scv, mscv);
            scv = 0;
        }
    }
    cout << mscv;
    return 0;
}
