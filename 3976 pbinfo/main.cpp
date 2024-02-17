#include <iostream>

using namespace std;

int main()
{
    long long n, i, p = 1, nr = 1;
    cin >> n;
    while(n)
    {
        p *= nr;
        nr += 2;
        n--;
    }
    cout << p;
    return 0;
}
