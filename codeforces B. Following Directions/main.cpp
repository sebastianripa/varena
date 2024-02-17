#include <iostream>

using namespace std;

int main()
{
    int t, n, i1 = 0, j1 = 0, i;
    char c;
    bool ok = false;
    cin >> t;
    while(t--)
    {
        ok = false;
        i1 = 0;
        j1 = 0;
        cin >> n;
        cin.get(c);
        for(i = 1; i <= n; i++)
        {
            cin.get(c);
            if(c == 'U')
                i1++;
            else if(c == 'L')
                j1--;
            else if(c == 'D')
                i1--;
            else
                j1++;
            if(i1 == 1 && j1 == 1)
                ok = true;
        }
        if(ok)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
