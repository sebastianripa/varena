#include <iostream>

using namespace std;

int v[100];

int main()
{
    int t, n, k, p = 0, ps, s = 0, i, nr = 1, ans = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(p = 0; p < k && v[p] <= n; p++)
        {
            v[p] = nr;
            s += v[p];
            if(s > n)
            {
                ps = p-1;

            }
            nr *= 2;
        }
    }
    return 0;
}
