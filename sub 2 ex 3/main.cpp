#include <iostream>

using namespace std;

int v[7];

int main()
{
    int n, x, mij, i, in = 1, l;
    bool ok = false;
    cin >> n >> x;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    l = n;
    while(l != 0)
    {
        l = n - in + 1;
        if(l%2 == 0)
        {
            mij = (n + in)/2;
            if(x < v[mij])
                n = mij;
            else if(x > v[mij])
                in = mij + 1;
            else
            {
                cout << x;
                break;
            }
            cout << v[mij] << ' ';
        }
        else if(l != 1)
        {
            mij = (n + in)/2;
            if(x < v[mij])
                n = mij - 1;
            else if(x > v[mij])
                in = mij + 1;
            else
            {
                cout << x;
                break;
            }
            cout << v[mij] << ' ';
        }
        else
        {
            if(v[in] == x)
                cout << x;
            else
                cout << v[in];
            break;
        }
    }

    return 0;
}
