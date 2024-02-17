#include <iostream>

using namespace std;

int main()
{
    long long t, n, i, r = 0;
    bool g5 = false, g0 = false;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        r = 0;
        g5 = false;
        g0 = false;
        cin >> n;
        if(n%25 == 0)
            cout << 0 << '\n';
        else
        {
            while(n)
            {
                if(n%10 == 0 || g0)
                {
                    if((n%10 == 0 || n%10 == 5) && g0)
                    {
                        cout << r - 1 << '\n';
                        break;
                    }
                    else if((n%10 == 7 || n%10 == 2) && g5)
                    {
                        cout << r - 1 << '\n';
                        break;
                    }
                    g0 = true;
                }
                else if(n%10 == 5)
                    g5 = true;
                else if(g5)
                {
                    if((n%10 == 7 || n%10 == 2) && g5)
                    {
                        cout << r - 1 << '\n';
                        break;
                    }
                }
                r++;
                n /= 10;
            }
        }

    }
    return 0;
}
