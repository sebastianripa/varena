#include <iostream>

using namespace std;

int vf[123];

int main()
{
    int t, n, i, cnv;
    char c;
    bool ok = true;
    cin >> t;
    while(t--)
    {
        for(i = 97; i <= 122; i++)
            vf[i] = 0;
        ok = true;
        cin >> n;
        cin.get();
        for(i = 1; i <= n; i++)
        {
            cin.get(c);
            cnv = c;
            if(i%2 == 0)
            {
                if(vf[cnv] == 1)
                    ok = false;
                else
                    vf[cnv] = 2;
            }
            else
            {
                if(vf[cnv] == 2)
                    ok = false;
                else
                    vf[cnv] = 1;
            }
        }
        if(!ok)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}
