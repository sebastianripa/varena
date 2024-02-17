#include <bits/stdc++.h>

using namespace std;

ifstream fin ("intervale6.in");
ofstream fout ("intervale6.out");

long long v[200001];

int main()
{
    int n, i, nri = 0, x, y, l, r, mid;
    bool a = true;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    while(fin >> x >> y)
    {
        a = false;
        l = 1;
        r = n;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(x <= v[mid] && v[mid] <= y)
            {
                a = true;
                l = n+1;
            }
            if(v[mid] > y)
                r = mid-1;
            else if(v[mid] < x)
                l = mid + 1;
        }
        if(!a)
            nri++;
    }
    fout << nri;
    return 0;
}
