#include <iostream>

using namespace std;

int main()
{
    int m, n, i, j, cnt = 0;
    cin >> m;
    n = m*2 - 1;
    for(i = 1; i <= n/2; i++)
    {
        for(j = 1; j <= n/2 - cnt; j++)
            cout << '#';
        for(j = n/2 - cnt + 1; j <= n/2 + cnt + 1; j++)
            cout << '*';
        for(j = n/2 + cnt + 2; j <= n; j++)
            cout << '#';
        cnt++;
        cout << '\n';
    }
    for(i = 1; i <= n; i++)
        cout << '*';
    cout << '\n';
    cnt--;
    for(i = n/2 + 2; i <= n; i++)
    {
        for(j = 1; j <= n/2 - cnt; j++)
            cout << '#';
        for(j = n/2 - cnt + 1; j <= n/2 + cnt + 1; j++)
            cout << '*';
        for(j = n/2 + cnt + 2; j <= n; j++)
            cout << '#';
        cnt--;
        cout << '\n';
    }
    return 0;
}
