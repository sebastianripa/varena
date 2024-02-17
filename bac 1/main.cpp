#include <iostream>

using namespace std;

int main()
{
    int n, x, ogx, i, m;
    bool ok = false;
    cin >> n >> ogx;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        if(ogx > x && ogx == 0)
        {
            ok = 1;
            m = ogx;
        }
        else if(ok == 1 && ogx < x)
            break;
    }
    if(i == n+1)
        cout << m;
    else
        cout << x;
    return 0;
}
