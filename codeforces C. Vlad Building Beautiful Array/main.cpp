#include <iostream>

using namespace std;

int main()
{
    int t, n, i, nri = 0, mini = 1000000001, x;
    cin >> t;
    while(t--)
    {
        mini = 1000000001;
        nri = 0;
        cin >> n;
        for(i = 1; i <= n ; i++)
        {
            cin >> x;
            if(x%2 == 1)
                nri++;
            mini = min(x, mini);
        }
        if(mini%2 == 1)
            cout << "YES" << '\n';
        else
        {
            if(nri == 0)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}
