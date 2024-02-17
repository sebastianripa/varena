#include <iostream>

using namespace std;

int e[4], o[4];

int main()
{
    int t, n, i, j, x, e1 = 0, o1 = 0;
    cin >> t;
    while(t--)
    {
        for(i = 1; i <= 3; i++)
        {
            o[i] = 0;
            e[i] = 0;
        }
        e1 = 0;
        o1 = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x%2 == 0)
            {
                if(e[1] == 0)
                {
                    e[1] = i;
                    e1++;
                }
                else if(e[2] == 0)
                {
                    e[2] = i;
                    e1++;
                }
                else if(e[3] == 0)
                {
                    e[3] = i;
                    e1++;
                }
            }
            else
            {
                if(o[1] == 0)
                {
                    o[1] = i;
                    o1++;
                }
                else if(o[2] == 0)
                {
                    o[2] = i;
                    o1++;
                }
                else if(o[3] == 0)
                {
                    o[3] = i;
                    o1++;
                }
            }
        }
        if(o1 == 3)
        {
            cout << "YES" << '\n' << o[1] << ' ' << o[2] << ' ' << o[3] << '\n';
        }
        else if(e1 >= 2 && o1 >= 1)
        {
            cout << "YES" << '\n' << o[1] << ' ';
            cout << e[1] << ' ' << e[2] << '\n';
        }
        else
            cout << "NO" << '\n';
    }
    return 0;
}
