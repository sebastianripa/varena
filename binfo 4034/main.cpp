#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a + b - 100 < 0)
        cout << 0;
    else
        cout << a + b - 100;
    return 0;
}
