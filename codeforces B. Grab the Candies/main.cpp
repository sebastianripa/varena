#include <iostream>

using namespace std;

int main()
{
    int t, n, x, s1 = 0, s2 = 0, i;
    cin >> t;
    while(t--)
    {
        s1 = 0;
        s2 = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x%2 == 0)
                s1 += x;
            else
                s2 += x;
        }
        if(s1 <= s2)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}
