#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long long n, a, b, i, sa = 0, sb = 0;
    float x;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        cin >> b;
        sa += a;
        sb += b;
    }
    x = max(sa, sb)/min(sa, sb);
    cout << setprecision(20) << x;
    return 0;
}
