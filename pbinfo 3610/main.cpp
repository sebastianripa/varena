#include <iostream>

using namespace std;

int main()
{
    int n, r;
    cin >> n;
    if(n <= 100)
        cout << 100;
    else if(n%100 == 0)
        cout << n;
    else
    {
        n += (100 - n%100);
        cout << n;
    }
    return 0;
}
