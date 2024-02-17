#include <iostream>

using namespace std;

int main()
{
    long long t, poz, n, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> poz >> n;
        if(n%4 == 1)
        {
            if(poz%2 == 0)
                poz -= n;
            else
                poz += n;
        }
        else if(n%4 == 2)
        {
            if(poz%2 == 0)
                poz++;
            else
                poz--;
        }
        else if(n%4 == 3)
        {
            if(poz%2 == 0)
                poz += ++n;
            else
                poz -= ++n;
        }
        cout << poz << '\n';
    }
    return 0;
}
