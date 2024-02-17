#include <iostream>

using namespace std;

int main()
{
    int x, n, r;
    cin >> x >> n;
    if(n%2 == 1)
        r = (n+1)/2-2;
    else
        r = n/2-2;
    cout << n+r << x;
    return 0;
}
