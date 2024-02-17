#include <iostream>

using namespace std;

int main()
{
    long long p, q, n, i, pr, x, cx, e1 = 0, e2 = 0;
    cin >> p >> q >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        cx = x;
        while(cx%p == 0)
        {
            e1++;
            cx /= p;
        }
        while(x%q == 0)
        {
            e2++;
            x /= q;
        }
    }
    cout << min(e1, e2);
    return 0;
}
