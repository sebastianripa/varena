#include <iostream>

using namespace std;

int main()
{
    long long t, n, a, b, x, y, p1, p2, pc;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> x >> y;
        if(max(a, b) > n/2)
            pc = n - max(a, b)+1;
        else
            pc = max(a, b);
        if(min(a, b) > n/2)
            p1 = n-min(a, b)+1;
        else
            p1 = min(a, b);
        p1 = min(p1, pc);
        if(max(x, y) > n/2)
            pc = n - max(x, y)+1;
        else
            pc = max(x, y);
        if(min(x, y) > n/2)
            p2 = n-min(x, y)+1;
        else
            p2 = min(x, y);
        p2 = min(p2, pc);
        cout << max(p1, p2) - min(p1, p2) << '\n';
    }
    return 0;
}
