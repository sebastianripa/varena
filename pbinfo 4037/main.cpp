#include <iostream>

using namespace std;

int v[2000001];

int main()
{
    int n, x, k, p = 0, q = 0, r = 0, i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cin >> x >> k;
    for(i = 1; i <= n; i++)
    {
        if(v[i] == x)
        {
            if(p == 0)
                p = i;
            else if(k == 1)
                r = i;
            q = i;
            k--;
        }
    }
    cout << p << '\n' << q << '\n' << r;
    return 0;
}
