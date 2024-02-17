#include <iostream>

using namespace std;

char m[1000][1000];

int main()
{
    int n, mn, k, i, j, ans = 0, ck, cj, ci;
    bool ok = true;
    cin >> n >> mn >> k;
    for(i = 1; i <= n; i++)
    {
        cin.get();
        for(j = 1; j <= mn; j++)
            cin.get(m[i][j]);
    }
    for(i = 1; i <= n-2*k; i++)
    {
        for(j = 1; j <= mn-k; j++)
        {
            ok = true;
            ck = 2*k;
            ci = i;
            cj = j;
            while(ck--)
            {
                if(m[ci][cj] != m[i][j])
                    ok = false;
                ci++;
            }
            ck = k;
            ci = i;
            cj = j;
            while(ck--)
            {
                if(m[ci][cj] != m[i][j])
                    ok = false;
                cj++;
            }
            ck = k;
            ci = i;
            cj = j+k;
            while(ck--)
            {
                if(m[ci][cj] != m[i][j])
                    ok = false;
                ci++;
            }
            ck = k;
            ci = i+k;
            cj = j+k;
            while(ck--)
            {
                if(m[ci][cj] != m[i][j])
                    ok = false;
                cj--;
            }
            ck = k;
            ci = i+k;
            cj = j;
            while(ck--)
            {
                if(m[ci][cj] != m[i][j])
                    ok = false;
                ci++;
                cj++;
            }
            if(ok)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
