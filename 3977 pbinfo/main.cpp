#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, p = 1, e = 0;
    cin >> n;
    while(p < n)
    {
        p *= 2;
        e++;
    }
    if(e == 0 || p == n)
        e++;
    cout << e - 1;
    return 0;
}
