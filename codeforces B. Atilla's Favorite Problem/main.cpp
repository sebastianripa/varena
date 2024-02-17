#include <iostream>

using namespace std;

int main()
{
    int t, n, maxi = 0, i, j, inter;
    char c;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        maxi = 0;
        cin >> n;
        cin.get(c);
        for(j = 1; j <= n; j++)
        {
            cin.get(c);
            inter = c - 96;
            maxi = max(maxi, inter);
        }
        cout << maxi << '\n';
    }
    return 0;
}
