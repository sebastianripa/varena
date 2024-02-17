#include <iostream>

using namespace std;

int main()
{
    unsigned long long t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%2 == 0)
            cout << 2 + 2*n*(n/2 + 1) << '\n';
        else
            cout << 1 + (n+1)*(n+1) << '\n';
    }
}
