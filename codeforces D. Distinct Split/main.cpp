#include <iostream>

using namespace std;

int v1[200005], v2[200005], vf1[123], vf2[123];
char v[200005];

int main()
{
    int t, n = 0, i, j, maxi = 0;
    cin >> t;
    while(t--)
    {
        maxi = 0;
        for(i = 97; i <= 122; i++)
        {
            vf1[i] = 0;
            vf2[i] = 0;
        }
        for(i = 1; i <= n; i++)
        {
            v1[i] = 0;
            v2[i] = 0;
        }
        cin >> n;
        cin >> v;
        v1[1] = 1;
        vf1[v[0]]++;
        for(i = 2; i <= n; i++)
        {
            if(vf2[v[i-1]] == 0)
            {
                v2[1]++;
                vf2[v[i-1]]++;
            }
            else
                vf2[v[i-1]]++;
        }
        for(i = 2; i <= n-1; i++)
        {
            if(vf1[v[i-1]]++ == 0)
                v1[i] = v1[i-1] + 1;
            else
                v1[i] = v1[i-1];
            if(vf2[v[i-1]]-- == 1)
                v2[i] = v2[i-1] - 1;
            else
                v2[i] = v2[i-1];
        }
        for(i = 1; i <= n-1; i++)
            maxi = max(maxi, v1[i]+v2[i]);
        cout << maxi << '\n';
    }
    return 0;
}
