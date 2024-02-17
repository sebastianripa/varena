#include <iostream>

using namespace std;

int main()
{
    long long t, n, k, q, ls = 0, i, x, ans = 0;
    cin >> t;
    while(t--)
    {
        ans = 0;
        ls = 0;
        cin >> n >> k >> q;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x <= q)
                ls++;
            else
            {
                if(ls >= k)
                {
                    ls -= k;
                    ls++;
                    ans += ls*(ls+1)/2;
                }
                ls = 0;
            }
        }
        if(ls >= k)
        {
            ls -= k;
            ls++;
            ans += ls*(ls+1)/2;
            ls = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}
