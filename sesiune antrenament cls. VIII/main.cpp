#include <iostream>
#include <algorithm>

using namespace std;

int v[140001], vs[70001];

int main()
{
    int n, c, i, j;
    cin >> c >> n;
    if(c == 1)
    {
        for(i = 1; i <= n*2; i++)
            cin >> v[i];
        sort(v+1, v+n*2+1);
        cout << v[1] + v[2] << " " << v[n*2] + v[n*2-1];
    }
    else
    {
        for(i = 1; i <= n*2; i++)
            cin >> v[i];
        sort(v+1, v+n*2+1);
        for(i = 1, j = n*2; i <= n && j >= n+1; i++, j--)
            vs[i] = v[i] + v[j];
        for(i = 2; i <= n; i++)
        {
            if(vs[i] != vs[i-1])
                break;
        }
        if(i == n+1)
            cout << "DA" << '\n' << max(v[n], v[n+1])-min(v[n], v[n+1]);
        else
            cout << "NU";
    }
    return 0;
}
