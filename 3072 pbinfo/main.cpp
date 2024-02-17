#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;
    a = n/3;
    if(n%3 == 1)
    {
        b = n/3;
        c = n/3+1;
        cout << a << " " << b << " " << c;
    }
    else if(n%3 == 2)
    {
        b = n/3+1;
        c = n/3+1;
        cout << a << " " << b << " " << c;
    }
    else
    {
        b = n/3;
        c = n/3;
        cout << a << " " << b << " " << c;
    }
    return 0;
}
