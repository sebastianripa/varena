#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("bas.in");
ofstream fout ("bas.out");

pair<int, int> v[100001];
int fct;

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void desc(int n)
{
    int f = 2, i = 1, e = 0;
    while(f*f <= n)
    {
        e = 0;
        while(n%f == 0)
        {
            n /= f;
            e++;
        }
        if(e != 0)
        {
            v[i].first = f;
            v[i++].second = e;
        }
        f++;
    }
    if(n != 1)
    {
        v[i].first = n;
        v[i++].second = 1;
    }
    fct = i-1;
}

int main()
{
    int p, n, m, i, x, dc, et = 0, j;
    cin >> p >> m >> n;
    if(p == 1)
    {
        cin >> x;
        dc = x;
        for(i = 2; i <= n; i++)
        {
            cin >> x;
            dc = cmmdc(dc, x);
        }
        for(i = 1; i <= m; i++)
        {
            cin >> x;
            if(dc%x == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    else
    {
        cin >> x;
        dc = x;
        for(i = 2; i <= n; i++)
        {
            cin >> x;
            dc = cmmdc(x, dc);
        }
        desc(dc);
        for(i = 1; i <= m; i++)
        {
            int ans = 0;
            cin >> x;
            for(j = 1; j <= fct; j++)
            {
                et = 0;
                while(x%v[j].first == 0)
                {
                    x /= v[j].first;
                    et++;
                }
                ans += v[j].second - et;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
