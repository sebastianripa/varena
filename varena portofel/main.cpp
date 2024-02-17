#include <bits/stdc++.h>
#define cout fout
#define cin fin

using namespace std;

ifstream fin ("portofel.in");
ofstream fout ("portofel.out");

int vf[100001];
set<int> p1;
set<int> p2;

int main()
{
    int n, n1, x, maxi = 0, i, j, ans = 0;
    bool ok = true;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        p1[1].insert(x);
        vf[x]++;
        maxi = max(maxi, vf[x]);
    }
    cin >> n1;
    for(i = 1; i <= n1; i++)
    {
        cin >> x;
        p2[1].insert(x);
        vf[x]++;
        maxi = max(maxi, vf[x]);
    }
    cout << maxi;
    i = 0;
    j = 0;
    n = p1.size()-1;
    while(i <= n)
    {
        if(p2[j] != p1[i])
        {
            if(ok)
            {
                ans++;
                ok = false;
            }
            i++;
            continue;
        }
        if(p2[j+1] == p1[i+1])
        {
            i += 2;
            j += 2;
            ans++;
            continue;
        }
        j++;
        i++;
        ans++;
    }
    cout << ans;
    return 0;
}
