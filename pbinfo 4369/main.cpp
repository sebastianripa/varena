#include <bits/stdc++.h>

using namespace std;

int v[100005];

int main()
{
    int n, s = 0, i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    sort(v+1, v+n+1);
    for(i = 2; i <= n; i++)
        s += (v[i] - v[1]);
    cout << s;
    return 0;
}
