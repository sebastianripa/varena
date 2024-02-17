#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("clepsidru.in");
ofstream fout ("clepsidru.out");

int v[2001];

int main()
{
    int n, b, nrs, s, p, i, j;
    cin >> n >> b;
    cout << n + b - 1 << '\n';
    cin >> nrs;
    v[1] = b;
    while(nrs--)
    {
        cin >> s >> p;
        if(p == 1)
        {
            for(i = 1; i < n*2; i++)
            {
                if(v[i] >= 1 && i%2 == 0)
                {
                    v[i+1] = v[i];
                    v[i] = 0;
                }
            }
            for(i = 1; i <= s; i++)
            {
                for(j = n*2-1; j >= 1; j-=2)
                {
                    if(v[j] >= 1)
                    {
                        if(j != n*2-1)
                            v[j+2]++;
                        else
                            v[j+1]++;
                        v[j]--;
                    }
                }
            }
        }
        else
        {
            for(i = n*2; i > 1; i--)
            {
                if(v[i] >= 1 && i%2 == 1)
                {
                    v[i-1] = v[i];
                    v[i] = 0;
                }
            }
            for(i = 1; i <= s; i++)
            {
                for(j = 2; j <= n*2; j+=2)
                {
                    if(v[j] >= 1)
                    {
                        if(j != 2)
                            v[j-2]++;
                        else
                            v[j-1]++;
                        v[j]--;
                    }
                }
            }
        }
    }
    for(i = 2; i <= n*2; i+=2)
        cout << v[i-1] << ' ' << v[i] << '\n';
    return 0;
}
