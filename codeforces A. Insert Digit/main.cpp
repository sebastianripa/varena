#include <iostream>

using namespace std;

int main()
{
    int t, n, i, nr, ca;
    char c;
    bool ok = false;
    cin >> t;
    while(t--)
    {
        ok = false;
        cin >> n >> ca;
        cin.get();
        for(i = 1; i <= n; i++)
        {
            cin.get(c);
            nr = c - 48;
            if(ca < nr || (ok == true && ca >= nr))
                cout << nr;
            else if(ok == false && ca > nr)
            {
                cout << ca << nr;
                ok = true;
            }
            else if(ca == nr)
                cout << nr;
        }
        if(ok == false)
            cout << ca;
        cout << '\n';
    }
    return 0;
}
