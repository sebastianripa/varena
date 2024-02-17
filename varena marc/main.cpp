#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    int r = a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main()
{
    int x, y, m, nrr, i, d, ans = 0;
    cin >> x >> y;
    d = cmmdc(x, y);
    nrr = y/d;
    m = (nrr-1)*(x/y+1) + x/y;
    cout << m << '\n';
    for(i = 1; i <= x; i++)
    {
        if(d == cmmdc(x, i))
            ans++;
    }
    cout << ans;
    return 0;
}
