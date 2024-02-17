#include <iostream>

using namespace std;

int main()
{
    int t, n, c1 = 0, c2 = 0, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> n;
        if(n%3 == 0)
        {
            c1 = n/3;
            n -= n/3;
            c2 = n/2;
        }
        else if(n%3 == 1)
        {
            n -= 1;
            c1 = n/3 + 1;
            n -= n/3;
            c2 = n/2;
        }
        else
        {
            n -= 2;
            c1 = n/3;
            n -= n/3;
            c2 = n/2 + 1;
        }
        cout << c1 << ' ' << c2 << '\n';
    }
    return 0;
}
