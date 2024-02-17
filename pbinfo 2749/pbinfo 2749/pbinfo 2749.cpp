#include <iostream>
#include <vector>

using namespace std;


#define MAXN 100000

int t[MAXN + 2], f[MAXN + 1];
vector<int> v[MAXN + 1];


void dfs(int nr)
{
    f[nr] = 1;
    for (auto i : v[nr])
        if (!f[i])
            dfs(i);
}

int main()
{
    int n;
    cin >> n;
    int i, ind;
    ind = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> t[i];
        if (t[i] != 0)
        {
            v[t[i]].push_back(i);
            v[i].push_back(t[i]);
        }
        else if (t[i] == 0)
            ind = i;
    }

    dfs(ind);

    int ok;
    ok = 0;
    for (i = 1; i <= n; i++)
        if (!f[i])
            ok++;

    if (ok == 0 && ind != 0)
        cout << "DA";
    else
        cout << "NU";
}