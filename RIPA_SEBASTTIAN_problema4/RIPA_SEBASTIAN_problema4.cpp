#include <iostream>

using namespace std;

int main()
{
    int x, nr = 27, nrp = 26, i = 1;
    char c;
    cin >> x;
    while(x > 0)
    {
        c = 65 + (x - 1)%26;
        cout << c;
        x = (x - 1)/26;
    }
    return 0;
}
