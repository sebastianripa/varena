#include <iostream>

using namespace std;

int main()
{
    long long n, maxi = 0, f = 10, x;
    cin >> n;
    while(f <= n*10)
    {
        x = (n/f)*(f/10)+n%(f/10);
        if((n/f)*(f/10)+n%(f/10) > maxi)
            maxi = (n/f)*(f/10)+n%(f/10);
        f *= 10;
    }
    cout << maxi;
    return 0;
}
