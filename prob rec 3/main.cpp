#include <iostream>

using namespace std;

int sum(int n, int sc = 0)
{
    if(n/10 == 0)
        return n;
    return n%10 + sum(n/10);
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n);
    return 0;
}