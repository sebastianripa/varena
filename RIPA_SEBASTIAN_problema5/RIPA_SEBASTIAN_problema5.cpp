#include <bits/stdc++.h>

using namespace std;

bool eValid(const vector<int>& v, int x, int k)
{
    int ct = 0, i;
    for(i = 1; i <= v.size(); i++)
    {
        if(v[i] >= x)
            ct++;
    }
    return ct <= k;
}

int ans(const vector<int>& v, int k, int maxi)
{
    int s = 1, d = maxi, mij, rez = -1;
    while(s <= d)
    {
        mij = s + (d - s)/2;
        if(eValid(v, mij, k))
        {
            rez = mij;
            s = mij + 1;
        }
        else
            d = mij - 1;
    }
    return rez;
}

int main()
{
    int n, k, i, maxi;
    vector<int> v(n+1);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        maxi =  max(v[i], maxi);
    }
    cout << ans(v, k, maxi);
    return 0;
}
