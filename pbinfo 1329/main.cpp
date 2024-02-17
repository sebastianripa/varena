#include <iostream>

using namespace std;

int main()
{
    int n, y, x, i;
    bool a = true;
    cin >> n >> x >> y;
    if(x > y)
    {
        for(i = 3; i <= n; i++)
        {
            cin >> x;
            if((i-1)%2 == 1)
            {
                if(y <= x)
                    a = false;
            }
            else
            {
                if(y >= x)
                    a = false;
            }
            y = x;
        }
        if(a)
            cout << "DA";
        else
            cout << "NU";
    }
    else if(x < y)
    {
        for(i = 3; i <= n; i++)
        {
            cin >> x;
            if((i-1)%2 == 0)
            {
                if(y <= x)
                    a = false;
            }
            else
            {
                if(y >= x)
                    a = false;
            }
            y = x;
        }
        if(a)
            cout << "DA";
        else
            cout << "NU";
    }
    else
        cout << "NU";
    return 0;
}
