#include <iostream>

using namespace std;

int main()
{
    int a, b, ca, cb, r;
    cin >> a >> b;
    ca = a;
    cb = b;
    while(a%b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    cout << ca/b-1 + cb/b-1;
    return 0;
}
