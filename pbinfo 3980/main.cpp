#include <iostream>

using namespace std;

int main()
{
    int n, mini = 1001, maxi = 0, x, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    cout << maxi+mini;
    return 0;
}
