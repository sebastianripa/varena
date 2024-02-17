#include <iostream>
#include <algorithm>

using namespace std;

char v[100000], v2[100000];

int main()
{
    int t, n, i, j, p = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        p = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i];
            v2[i] = v[i];
        }
        sort(v+1, v+n+1);
        for(i = 1; i <= n; i++)
        {
            if(v[i] != v2[i])
                p++;
        }
        cout << p << '\n';
    }
    return 0;
}
